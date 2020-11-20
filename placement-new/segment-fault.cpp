#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  // Fine
  int i = 10;
  int *ipt = &i;
  int *i1 = new (ipt) int(9);

  // Segment fault
  // Incorrect as ip may not be a valid address
  // int *ip;
  // int *i2 = new (ip) int(4);

  // Fine
  void *vd = &i;
  int *i3 = new (vd) int(34);

  // Compile error
  // Incorrect as x is not an address
  // int x;
  // int *i5 = new (x) int(3);
  
  return 0;
}

