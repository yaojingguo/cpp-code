#include <stdio.h>


void info() {
  printf("INFO");
}

int main(int argc, char *argv[]) {
  show(); 
  return 0;
}
// compiler error
#define show info
