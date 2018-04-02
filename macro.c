#include <stdio.h>

#define info cool_info

void info() {
  printf("INFO\n");
}

#define cool_debug debug
void debug() {
  printf("DEBUG\n");
}

int main() {
  info();
  cool_info();

  debug();
  cool_debug();
}

/*
void cool_info() {
  printf("INFO\n");
  }


  void debug() {
    printf("DEBUG\n");
    }

    int main() {
      cool_info();
        cool_info();

          debug();
            debug();
            }



*/
