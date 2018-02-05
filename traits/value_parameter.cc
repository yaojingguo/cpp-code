#include <iostream>
using namespace std;

template<typename T, int max>
class Buffer {
public:
  Buffer() {}
private:
  T v[max];
};

int main(int argc, char const *argv[]) {
  Buffer<char, 128> cbuf;
  Buffer<int, 10> ibuf;

  return 0;
}
