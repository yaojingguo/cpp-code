#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

void MyFunc(int c) {
  if (c > numeric_limits<char>::max()) {
    throw string("MyFunc argument too large");
  }
}

int main(int argc, char const *argv[]) {
  // int value = numeric_limits<char>::max();
  // cout << "max: " <<  value << endl;
  // Record the strange no number result
  try {
    MyFunc(256);
  } catch (string& e) {
    cerr << e << endl;
    return -1;
  }
  return 0;
}
