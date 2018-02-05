#include <iostream>
#include <string>

using namespace std;

template<typename T, int max>
class Buffer {
public:
  Buffer() {
  }
private:
  T v[max];
};

template <typename T, char* label>
class X {

};

template<typename T, T default_value>
class Vec {

};

template<typename T, T default_value = T{}>
class Vec2 {

};


int main(int argc, char const *argv[]) {
  Buffer<char, 128> cbuf;
  Buffer<int, 10> ibuf;

  // char lx2[] = "BMW323Ci";
  // X<int, lx2> xx;

  constexpr int max = 20;
  Buffer<int, max> bm;

  Vec<int, 42> c1;
  Vec2<int> c11;


  // Vec<string, string("")> c2;

  return 0;
}
