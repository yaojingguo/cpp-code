#include <cstdio>

int fn() __attribute__((warn_unused_result));

int foo () {
  if (fn() < 0) return -1;
  fn();
  return 0;
}

int fn() {
  return 10;
}

int main(int argc, char *argv[]) {
  foo();  
  return 0;
}
