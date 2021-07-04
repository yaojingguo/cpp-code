#include <iostream>
#include <string>

using namespace std;

struct W {
  W(int&, int&) {}
};

struct X {
  X(const int&, int&) {}
};

struct Y {
  Y(int&, const int&) {}
};

struct Z {
  Z(const int&, const int&) {}
};

// template<typename T, typename A1, typename A2>
// T* factory(A1& a1, A2& a2) {
//    return new T(a1, a2);
// }

template <typename T, typename A1, typename A2>
T* factory(A1&& a1, A2&& a2) {
  return new T(std::forward<A1>(a1), std::forward<A2>(a2));
}

// reference-overload.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock {
  // TODO: Add resources for the class here.
};

void f(const MemoryBlock&) {
  cout << "In f(const MemoryBlock&). This version cannot modify the parameter."
       << endl;
}

void f(MemoryBlock&&) {
  cout << "In f(MemoryBlock&&). This version can modify the parameter." << endl;
}

void one() {
  // int a = 4, b = 5;
  // W* pw = factory<W>(a, b);
  // X* px = factory<X>(2, b);
  // Y* py = factory<Y>(a, 2);
  // Z* pz = factory<Z>(2, 2);

  // delete pw;
  // delete px;
  // delete py;
  // delete pz;
}

int main() {
  // MemoryBlock block;
  // f(block);
  // f(MemoryBlock());
  int a = 4, b = 5;
  W* pw = factory<W>(a, b);
  Z* pz = factory<Z>(2, 2);
}
