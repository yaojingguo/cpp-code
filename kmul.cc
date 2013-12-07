#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

// Use little endian
using namespace std;

#define word unsigned long long
#define byte unsigned int 

#define LSB_MASK  0xFFFFFFFF

word byte_add(byte a, byte b, byte carry, byte& lsb, byte& msb)
{
  word sum = (word) a + (word) b + (word) carry;
  lsb = sum & LSB_MASK;
  msb = sum >> 32;
}

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
    printf("lsb: 0X%x, msb: 0X%x\n", lsb, msb);
    dest[i] = lsb;
    carry = msb;
  }
  while (dest.back() == 0)
    dest.pop_back();
  while (src.back() == 0)
    src.pop_back();
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

int main(int argc, const char *argv[]) 
{
  test_add();
}
