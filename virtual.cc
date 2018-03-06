#include <stdio.h>

class Thing {
  public:
    virtual void info();
};
void Thing::info() {
  printf("Thing\n");
}

class Live: public Thing {
  public:
    void info();
};
void Live::info() {
  printf("Live\n");
}

class Plant: public Live {
  public:
    void info();
};
void Plant::info() {
  printf("Plant\n");
}

int main(int argc, char *argv[]) {
  Thing* grass = new Plant();
  grass->info(); 
  return 0;
}

