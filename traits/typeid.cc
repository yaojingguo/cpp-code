#include <iostream>

using namespace std;

class A {

};

int main(int argc, char const *argv[]) {
  A* ptr;
  cout << "A*: " << typeid(A*).name() << endl;
  cout << "A*: " << typeid(ptr).name() << endl;
  return 0;
}
