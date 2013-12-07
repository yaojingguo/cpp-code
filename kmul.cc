#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

// Use little endian
using namespace std;

#define word unsigned long long
#define byte unsigned int 

#define LSB_MASK  0xFFFFFFFF

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
  new_carry = b > a ? 1 : 0;
}

// dest = src + dest
void add(vector<byte> src, vector<byte>& dest)
{
  int i, j, size;
  byte carry, lsb, msb;
  word sum; 
  size = max(src.size(), dest.size()) + 1;
  while (src.size() < size)
    src.push_back(0);
  while (dest.size() < size)
    dest.push_back(0);
  for (i = j = 0, carry = 0; i < src.size() && j < dest.size(); i++, j++) {
    byte_add(src[i], dest[i], carry, lsb, msb);
    // printf("lsb: 0X%x, msb: 0X%x\n", lsb, msb);
    dest[i] = lsb;
    carry = msb;
  }
  while (dest.back() == 0)
    dest.pop_back();
  while (src.back() == 0)
    src.pop_back();
}

// dest = dest - src
void sub(vector<byte>& src, vector<byte>& dest)
{
  int size = max(src.size(), dest.size());
  while (src.size() < size)
    src.push_back(0);
  while (dest.size() < size) 
    dest.push_back(0);
  int i;
  byte old_carry, new_carry, lsb;
  for (i = 0, old_carry = 0; i < size; i++) {
    byte_sub(src[i], dest[i], old_carry, lsb, new_carry);
    old_carry = new_carry;
    dest[i] = lsb;
  }
  while (dest.back() == 0)
    dest.pop_back();
}

// XXX Too many copies of bytes are made here.
// dest = src * dest
void mul(vector<byte>& src, vector<byte>& dest)
{
  int size = max(src.size(), dest.size());
  int split = size / 2;
  if (size == 1) {
    word product = (word) src[0] * (word) dest[0];
    dest[0] = to_lsb(product);
    dest.push_back(to_msb(product));
  }
  vector<byte> src_low(src.begin(), src.begin() + split);
  vector<byte> src_high(src.begin() + split, src.end());
  vector<byte> dest_low(dest.begin(), dest.begin() + split);
  vector<byte> dest_high(dest.begin() + split, dest.end());

  vector<byte> high_high(dest_high);
  mul(src_high, high_high);
  vector<byte> low(dest_low);
  mul(src_low, low);
  add(src_low, dest_high);
  add(src_high, dest_low);
  mul(dest_low, dest_high);

  sub(low, dest_high);
  sub(high_high, dest_high);
  
  for (int i = 0; i < 2 * split; i++)
    high_high.insert(high_high.begin(), 0);
  for (int i = 0; i < split; i++)
    dest_high.insert(dest_high.begin(), 0);
  dest.clear();
  add(high_high, dest);
  add(dest_high, dest);
  add(low, dest);
}

void info(vector<byte> a)
{
  printf("0x");
  for (int i = a.size() - 1; i >= 0; i--)
    printf("%X", a[i]);
  printf("\n");
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
  info(dest);

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
  info(dest);
}

void test_sub()
{
}

void test_mul()
{
}

int main(int argc, const char *argv[]) 
{
  test_add();
  test_sub();
  test_mul();
}
