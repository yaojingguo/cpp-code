#include <stdio.h>
#include "foo.h"

void bar();

int main(void) {
  puts("This is a shared library test...");
  foo();
  bar();
  return 0;
}

