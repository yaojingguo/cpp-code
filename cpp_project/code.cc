#include <iostream>

using namespace std;

void inner(int& no) {

}

void func1(const int& no) {
  // compile error: candidate function not viable: 1st argument ('const int') would lose const qualifier
  // inner(no);
}

void func2(int& no) {

}

int value_func() {
  return 10;
}

int main(int argc, char const *argv[]) {
  // compile error: candidate function not viable: expects an l-value for 1st argument
  // func2(10);
  // compile error: candidate function not viable: expects an l-value for 1st argument
  // func2(value_func());
  // func1(100);
  cout << sizeof(void *) << endl;


  return 0;
}


