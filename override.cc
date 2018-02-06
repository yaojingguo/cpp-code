#include <iostream>

using namespace std;

class A {
public:
  virtual void info() {
    cout << "A" << endl;
  }
};

class B: public A {
public:
  virtual void info() override {
    cout << "B" << endl;
  }
};

int main(int argc, char const *argv[]) {
  A* a = new B();
  a->info();
  return 0;
}
