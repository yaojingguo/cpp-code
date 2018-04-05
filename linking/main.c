#include <stdio.h>
#include "greeting.h"

void bar();

int main(void) {
  puts("This is a shared library test...");
  foo();
  bar();
  return 0;
}

