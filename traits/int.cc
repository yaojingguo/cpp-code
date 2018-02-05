#include <iostream>

template <int i>
struct type_no {
  static const int value = 9;
};

template<>
struct type_no<10> {
  static const bool value = 10;
};

// template<>
// struct type_no<2> {
//   static const bool value = 20;
// };

int main() {
  // std::cout << type_no::value << std::endl;
  std::cout << type_no<10>::value << std::endl;
  std::cout << type_no<2>::value << std::endl;
}
