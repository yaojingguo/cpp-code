#include <iostream>

using namespace std;

template <typename T>

T myMax(T x, T y) {
  return (x > y) ? x : y;
}

int main() {
  cout << myMax<int>(3, 7) << endl;
}
