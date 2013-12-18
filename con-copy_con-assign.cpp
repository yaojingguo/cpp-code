#include <iostream>

using namespace std;

class thing {
  private:
    int no;

  public: 
    thing() 
    {
      no = 10;
      cout << "default constructor" << endl;
    }
    thing(const thing& other) 
    {
      no = other.no;
      cout << "copy constructor" << endl;
    }
    thing& operator = (thing& rhs)
    {
      cout << "assignment operator" << endl;
      return *this;
    }
    void info() {
      cout << "no: " << no << endl;
    }
};

void test1()
{
  thing one; // constructor
  one.info();

  thing one_ = thing(); // constructor
  one = one_; // assignment operator
  one.info();

  thing two(one); // copy constructor
  two.info();

  thing three = one;
  three.info();
}


thing func()
{
  thing t;
  return t;
}

thing static_func()
{
  static thing t; // Eliminate RVO
  return t;
}

// http://en.wikipedia.org/wiki/Return_value_optimization
void test2()
{
  thing t1 = func();
  t1.info();

  thing t2 = static_func();
  t2.info();
}

int main(int argc, const char *argv[]) 
{
  // test1();
  test2();
  return 0;
}
