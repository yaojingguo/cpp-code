#include <iostream>

using namespace std;

class thing {
  public: 
    thing() 
    {
      cout << "default constructor" << endl;
    }
    thing(const thing& other) 
    {
      cout << "copy constructor" << endl;
    }
    thing& operator = (thing& rhs)
    {
      cout << "assignment operator" << endl;
      return *this;
    }
};

int main(int argc, const char *argv[]) 
{
  thing one;
  thing one_ = thing();

  one = one_;
  thing two(one);

  return 0;
}
