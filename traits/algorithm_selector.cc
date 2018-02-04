#include <iostream>

// algorithm_selector
template<bool b>
struct algorithm_selector {
  template<typename T >
  static void implementation(T& object) {
    std::cout << "default_implementation" << std::endl;
  }
};

template<>
struct algorithm_selector<true> {
  template<typename T >
  static void implementation(T& object) {
    object.optimised_implementation();
  }
};

template <typename T>
struct supports_optimised_implementation {
  static const bool value = false;
};

template<typename T>
void algorithm(T& object ) {
  algorithm_selector<supports_optimised_implementation<T>::value>::implementation(object);
}

class ObjectA{
};

class ObjectB {
public:
  void optimised_implementation() {
    std::cout << "optimised_implementation" << std::endl;
  }
};

template<>
struct supports_optimised_implementation<ObjectB> {
  static const bool value = true;
};

int main(int argc, char* argv[]) {
  // calls default implementation
  ObjectA a;
  algorithm<ObjectA>(a);

  // calls ObjectB::optimised_implementation();
  ObjectB b;
  algorithm<ObjectB>(b);

  return 0;
}
