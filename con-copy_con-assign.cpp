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
  thing one; // constructor
  thing one_ = thing(); // constructor

  one = one_; // assignment operator
  thing two(one); // copy constructor

  return 0;
}
