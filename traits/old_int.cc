#include <iostream>

template <int i>
struct type_no {
  static const int value = 0;
  static void info() {
    std::cout << "0x" << std::endl;
  }
};

template<>
struct type_no<1> {
  static const bool value = 10;
  static void info() {
    std::cout << "1y" << std::endl;
  }
};

template<>
struct type_no<2> {
  static const bool value = 20;
  static void info() {
    std::cout << "2z" << std::endl;
  }
};

int main() {
  std::cout << type_no<0>::value << std::endl;
  std::cout << type_no<1>::value << std::endl;
  std::cout << type_no<2>::value << std::endl;

  type_no<0>::info();
  type_no<1>::info();
  type_no<2>::info();
}
