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

int main(int argc, const char *argv[]) 
{
  thing one; // constructor
  one.info();
  thing one_ = thing(); // constructor

  one = one_; // assignment operator
  one.info();
  thing two(one); // copy constructor
  two.info();

  return 0;
}
