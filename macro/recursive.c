#include <stdio.h>

#define alias2 alias1
#define alias1 info

void info() {
  printf("INFO\n");
}

#define ref1 debug
#define ref2 ref1

void debug() {
  printf("DEBUG\n");
}

int main(int argc, char *argv[]) {
  alias2(); 
  alias1(); 
  info();

  ref2();
  ref1();
  debug();
  return 0;
}
