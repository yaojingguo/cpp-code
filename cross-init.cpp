// See discussion:
// http://stackoverflow.com/questions/92396/why-cant-variables-be-declared-in-a-switch-statement
#include <iostream>

using namespace std;

class X {
  public:
    X() 
    {
     cout << "constructor" << endl;
    }
    ~X() 
    {
     cout << "destructor" << endl;
    }
};

template <class type>
void ill_formed()
{
  goto lx;
ly:
  type a;
lx:
  goto ly;
}

template <class type>
void ok()
{
ly:
  type a;
lx:
  goto ly;
}

void test_class()
{
  ok<X>();
  // compile error
  ill_formed<X>();
}

void test_scalar() 
{
  ok<int>();
  ill_formed<int>();
}

int test1()
{
  int i = 0;
  // There jumps fo "case 1" and "case 2"
  switch(i) {
    case 1:
      // Compile error because of the initializer
      int r = 1; 
      break;
    case 2:
      break;
  };
}

void test2()
{
  int i = 2;
  switch(i) {
    case 1:
      int r;
      r= 1; 
      break;
    case 2:
      cout << "r: " << r << endl;
      break;
  };
}

int main(int argc, const char *argv[]) 
{
  test1();
  test2();
  return 0;
}
