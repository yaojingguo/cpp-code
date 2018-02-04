#include <iostream>

template <typename T>
struct is_void {
  static const bool value = false;
};

template<>
struct is_void<void> {
  static const bool value = true;
};

template<typename T>
struct is_pointer {
  static const bool value = false;
};

template<typename T>
struct is_pointer<T*> {
  static const bool value = true;
};

int main() {
  std::cout << is_void<int>::value << std::endl;
  std::cout << is_void<void>::value << std::endl;

  std::cout << "is_pointer: " << is_pointer<int>::value << std::endl;
  std::cout << "is_pointer: " << is_pointer<int*>::value << std::endl;
}
