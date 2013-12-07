#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <string.h>

// Use little endian
using namespace std;

#define word unsigned long long
#define byte unsigned int 

#define LSB_MASK  0xFFFFFFFF

#define N 4096
char buf[N];

byte to_lsb(word a)
{
  return a & LSB_MASK;
}

byte to_msb(word a)
{
  return a >> 32;
}

void byte_add(byte a, byte b, byte carry, byte& lsb, byte& msb)
{
  word sum = (word) a + (word) b + (word) carry;
  lsb = to_lsb(sum);
  msb = to_msb(sum);
}

void byte_sub(byte a, byte b, byte old_carry, byte& lsb, byte& new_carry)
{
  word a_w = (word) a;
  word b_w = (word) b;
  word old_carry_w = (word) old_carry;
  word diff = b_w - (a_w + old_carry);
  lsb = to_lsb(diff);
  new_carry = b < a ? 1 : 0;
}

void to_str(vector<byte>& a, char str[], int size)
{
  char* q = str;
  int cnt;
  int max_idx = a.size() - 1;
  for (int i = max_idx; i >= 0; i--) {
    if (i == max_idx) 
      cnt = snprintf(q, size, "0x%X", a[i]);
    else
      cnt = snprintf(q, size, "%08X", a[i]);
    size -= cnt;
    q += cnt;
    assert(size > 0);
  }
}

void pad(vector<byte>& src, vector<byte>& dest, int size)
{
  while (src.size() < size)
    src.push_back(0);
  while (dest.size() < size) 
    dest.push_back(0);
}

void normalize(vector<byte>& num)
{
  while (num.back() == 0)
    num.pop_back();
}

// dest = src + dest
void add(vector<byte>& src, vector<byte>& dest)
{
  int i, j, size;
  byte carry, lsb, msb;
  word sum; 
  size = max(src.size(), dest.size()) + 1;
  pad(src, dest, size);
  for (i = j = 0, carry = 0; i < src.size() && j < dest.size(); i++, j++) {
    byte_add(src[i], dest[i], carry, lsb, msb);
    dest[i] = lsb;
    carry = msb;
  }
  normalize(src);
  normalize(dest);
}

// dest = dest - src
void sub(vector<byte>& src, vector<byte>& dest)
{
  int size = max(src.size(), dest.size());
  pad(src, dest, size);
  int i;
  byte old_carry, new_carry, lsb;
  for (i = 0, old_carry = 0; i < size; i++) {
    byte_sub(src[i], dest[i], old_carry, lsb, new_carry);
    old_carry = new_carry;
    dest[i] = lsb;
  }
  normalize(src);
  normalize(dest);
}

// XXX Too many copies of bytes are made here.
// dest = src * dest
void mul(vector<byte>& src, vector<byte>& dest)
{
  int size = max(src.size(), dest.size());
  pad(src, dest, size);
  if (size == 1) {
    word product = (word) src[0] * (word) dest[0];
    dest[0] = to_lsb(product);
    dest.push_back(to_msb(product));
    return;
  }
  int split = size / 2;
  vector<byte> src_low(src.begin(), src.begin() + split);
  vector<byte> src_high(src.begin() + split, src.end());
  vector<byte> dest_low(dest.begin(), dest.begin() + split);
  vector<byte> dest_high(dest.begin() + split, dest.end());

  vector<byte> high_high(dest_high);
  mul(src_high, high_high);
  vector<byte> low(dest_low);
  mul(src_low, low);
  add(src_low, src_high);
  add(dest_low, dest_high);
  mul(src_high, dest_high);
  
  sub(low, dest_high);
  sub(high_high, dest_high);
  
  for (int i = 0; i < 2 * split; i++)
    high_high.insert(high_high.begin(), 0);
  for (int i = 0; i < split; i++)
    dest_high.insert(dest_high.begin(), 0);
  dest.clear();
  dest.push_back(0);
  add(high_high, dest);
  add(dest_high, dest);
  add(low, dest);
}

void test_mul_instruction()
{
  byte a = 0xFFFFFFFF;
  byte b = 0XFFFFFFFF;
  word c = (word) a * (word) b;
  printf("%llu\n", c);
}

void test_add()
{
  vector<byte> src;
  vector<byte> dest;

  src.push_back(0xFFFFFFFF);
  dest.push_back(0xFFFFFFFF);
  add(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0x1FFFFFFFE", buf) == 0);


  src.clear();
  dest.clear();
  // src: 0xABCDF0000000FFFFFFFF
  src.push_back(0xFFFFFFFF);
  src.push_back(0xF0000000);
  src.push_back(0xABCD);
  // src: 0xE0000001FFFFFFFF
  dest.push_back(0xFFFFFFFF);
  dest.push_back(0xE0000001);
  add(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0xABCED0000002FFFFFFFE", buf) == 0);
}

void test_sub()
{
  vector<byte> src;
  vector<byte> dest;
  dest.push_back(0xFFFF0000);
  src.push_back( 0xFF000000);
  sub(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0xFF0000", buf) == 0);

  src.clear();
  dest.clear();
  dest.push_back(0x1);
  dest.push_back(0xFF);
  src.push_back(0x2);
  src.push_back(0xF0);
  sub(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0xEFFFFFFFF", buf) == 0);
}

void test_mul()
{
  vector<byte> src;
  vector<byte> dest;
  src.push_back(0xFFFFFFFF);
  dest.push_back(0x11111111);
  mul(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0x11111110EEEEEEEF", buf) == 0);

  src.clear();
  dest.clear();
  // src:  0xFF000000FE
  // dest: 0x10000000010
  src.push_back(0xFE);
  src.push_back(0xFF);
  dest.push_back(0x10);
  dest.push_back(0x100);
  mul(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0xFF0000010DF000000FE0", buf) == 0);

  src.clear();
  dest.clear();
  // src:  0x000000FF000000FE
  // dest: 0xFFFFFFFDFFFFFFFF 
  src.push_back(0xFE);
  src.push_back(0xFF);
  dest.push_back(0xFFFFFFFF);
  dest.push_back(0xFFFFFFFD);
  mul(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0xFEFFFFFEFFFFFFFD04FFFFFF02", buf) == 0);

  src.clear();
  dest.clear();
  src.push_back(0x12345678);
  src.push_back(0xAABB5643);
  src.push_back(0x756868AB);
  src.push_back(0xFFFFEEEE);
  src.push_back(0x98790ACD);
  src.push_back(0x88660011);
  src.push_back(0x87097922);
  src.push_back(0x87609798);

  dest.push_back(0xAAA7DCAC);
  dest.push_back(0x90789878);
  dest.push_back(0x87698152);
  dest.push_back(0x87658222);
  dest.push_back(0x87091789);
  dest.push_back(0x13678689);
  dest.push_back(0x90756784);
  dest.push_back(0xAAAA1122);
  mul(src, dest);
  to_str(dest, buf, N);
  assert(strcmp("0x5A4013DFA63FA51DB98A302172759F41"
                "40FF7F8F0100F7611012289B5371283D53"
                "7FCCC3202CD44AE56E00920E05CC4D0B31"
                "B29143BB076927F702854DC138A0", buf) == 0);
}

int main(int argc, const char *argv[]) 
{
  test_add();
  test_sub();
  test_mul();
}
