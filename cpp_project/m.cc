#include <iostream>
#include <utility>
#include <vector>
#include <utility>

using namespace std;

class Foo {
 public:
  Foo() { std::cout << "Default Constructor: " << Info() << std::endl; }

  Foo(const std::string& s, const std::vector<int>& v) : s_(s), v_(v) {
    std::cout << "User-Defined Constructor: " << Info() << std::endl;
  }

  ~Foo() { std::cout << "Destructor: " << Info() << std::endl; }

  Foo(const Foo& f) : s_(f.s_), v_(f.v_) {
    std::cout << "Copy Constructor: " << Info() << std::endl;
  }

  Foo& operator=(const Foo& f) {
    s_ = f.s_;
    v_ = f.v_;
    std::cout << "Copy Assignment: " << Info() << std::endl;
    return *this;
  }

  Foo(Foo&& f) : s_(std::move(f.s_)), v_(std::move(f.v_)) {
    std::cout << "Move Constructor: " << Info() << std::endl;
  }

  Foo& operator=(Foo&& f) {
    s_ = std::move(f.s_);
    v_ = std::move(f.v_);
    std::cout << "Move Assignment: " << Info() << std::endl;
    return *this;
  }

  std::string Info() {
    return "{" + (s_.empty() ? "'empty'" : s_) + ", " +
           std::to_string(v_.size()) + "}";
  }

 private:
  std::string s_;
  std::vector<int> v_;
};

void call(Foo&& f) {
  cout << f.Info() << endl;
}

int main() {
  vector<int> vec = {1, 2, 3};
  Foo f3("abc", vec);
  Foo f4 = std::move(f3);
  cout << f3.Info() << endl;
  cout << f4.Info() << endl;
}

