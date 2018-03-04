#include <stdio.h>

int __attribute((weak)) foo();

int main() {
  printf("%d\n", foo());
}
