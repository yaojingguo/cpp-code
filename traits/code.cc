#include <iostream>

template <int i>
struct type_no {
  static const int value = 0;
};

template<>
struct type_no<1> {
  static const bool value = 10;
};

template<>
struct type_no<2> {
  static const bool value = 20;
};

int main() {
  std::cout << type_no<0>::value << std::endl;
  std::cout << type_no<1>::value << std::endl;
  std::cout << type_no<2>::value << std::endl;
}
