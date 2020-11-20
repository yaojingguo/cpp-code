// forward example
#include <utility>      // std::forward
#include <iostream>     // std::cout

// function with lvalue and rvalue reference overloads:
void overloaded (const int& x) {std::cout << "[lvalue]" << std::endl;}
void overloaded (int&& x) {std::cout << "[rvalue]" << std::endl;}

// function template taking rvalue reference to deduced type:
template <class T> 
void fn (T&& x) {
  overloaded (x);                   // always an lvalue
  overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
}

int main () {
  int a;

  std::cout << "calling fn with lvalue:" << std::endl;;
  fn (a);
  std::cout << '\n';

  std::cout << "calling fn with rvalue:" << std::endl;;
  fn (0);
  std::cout << '\n';

  return 0;
}
