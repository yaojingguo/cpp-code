#include <iostream>

using namespace std;

// No segment fault
void stack() {
  short s = 10;
  int* p = (int*) &s;
  int* pi = new (p) int(0x7FFFFFFF);
  cout << "int: " << *pi << endl;
}

// No segment fault
void heap() {
  void* s = malloc(2);
  int* p = (int*) s;
  int* pi = new (p) int(0x7FFFFFFF);
  cout << "int: " << *pi << endl;
}

int main(int argc, char *argv[]) {
  cout << "int size: " << sizeof(int) << endl;
  stack();
  heap();
  return 0;
}
