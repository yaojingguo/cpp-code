#include <iostream>

using namespace std;

constexpr int fib(int n) {
  return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[]) {
  int res = fib(4);
  cout << res << endl;
  return 0;
}
