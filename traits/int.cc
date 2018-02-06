#include <iostream>

template <typename T>
struct is_void {
  static const bool value = false;
};

template<>
struct is_void<void> {
  static const bool value = true;
};

template <typename T>
struct type_no {
  static const int value = 0;
};

template <>
struct type_no<int> {
  static const int value = 1;
};

template <>
struct type_no<float> {
  static const int value = 2;
};

template <bool i>
struct X {
  static void info() {
    std::cout << "default";
  }
};

template <>
struct X<true> {
  static void info() {
    std::cout << "default";
  }
};

// template <>
// struct X<2> {
//   static void info() {
//     std::cout << "20";
//   }
// };

int main() {
  // std::cout << type_no::value << std::endl;
  std::cout << is_void<void>::value << std::endl;
  std::cout << is_void<int>::value << std::endl;

  std::cout << type_no<void>::value << std::endl;
  std::cout << type_no<int>::value << std::endl;
  std::cout << type_no<float>::value << std::endl;

  std::cout << X<1>::info() << std::endl;
  // std::cout << X<1>::info() << std::endl;
  // std::cout << X<2>::info() << std::endl;
}
