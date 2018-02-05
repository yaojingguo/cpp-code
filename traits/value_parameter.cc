#include <iostream>
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

int main(int argc, char const *argv[]) {
  Buffer<char, 128> cbuf;
  Buffer<int, 10> ibuf;

  // char lx2[] = "BMW323Ci";
  // X<int, lx2> xx;

  constexpr int max = 20;
  Buffer<int, max> bm;

  return 0;
}
