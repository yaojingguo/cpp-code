#include <iostream>

using namespace std;

class person {
  public:
    person() {
      cout << "constructor" << endl;
    }
    person(const person& other) {
      cout << "copy constructor" << endl;
    }
};

int main(int argc, const char *argv[]) 
{
  person p;
  person q = p;
  return 0;
}
