#include <stdio.h>

class Call {
  public:
    int plus_one(int num) 
    {
      return num + 1;
    }
};

template<class S> void 
use(S* c, int (S::*method)(int), int i) {
  int result = (c->*method)(i);
  printf("result is %d\n", result);
}

int main(int argc, const char *argv[]) 
{
  Call *p = new Call;
  use(p, &Call::plus_one, 100);
  return 0;
}

