// This code is to illustrate how C++ handle non-virtual functions.
// Use "g++ S static.cpp" to produce static.s and remove all the .cfi 
// directies. Reading static.cpp and static.s gives a good understanding of 
// C++'s handling of non-virtual functions.
#include <stdio.h>
class Dog {
  public:
    Dog(int _age, int _sex) : 
      age(_age), sex(_sex) {}
    int grow(int increment);
    void info();
  private:
    int age;
    int sex;
};

int 
Dog::grow(int increment) 
{
  age += increment;
  return age;
}

void 
Dog::info() {
  printf("age: %d, sex: %d\n", age, sex);
}

int main(int argc, const char *argv[]) 
{
  Dog a(2, 0);
  a.grow(10);
  a.info();
  return 0;
}
