#include <stdio.h>
#include <assert.h>

using namespace std;

class Add {
  private:
    int x;
  public:
    Add(int x) : x(x) {}
    int operator()(int y) { return x + y; }
};

int function(int x)
{
  return x + 1;
}

template <class functor>
int func(functor f, int x) 
{
  int result = f(x);
  return result;
}

int main(int argc, const char *argv[]) 
{
  printf("result: %d\n", func(Add(1), 100));
  printf("result: %d\n", func(function, 100));
}
