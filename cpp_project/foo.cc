#include <iostream>
#include <string>
#include <vector>

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

void Proces(const Foo& f) {
  std::cout << "lvalue reference" << std::endl;
}

void Process(Foo&& f) {
  std::cout << "rvalue reference" << std::endl;
}

template <typename T>
void LogAndProcessNotForward(T&& a) {
  std::cout << a.Info() << std::endl;
  Process(a); 
}

template <typename T>
void LogAndProcessWithForward(T&& a) {
  std::cout << a.Info() << std::endl;
  Process(std::forward<T>(a));
}

void one() {
  std::vector<int> v1{1, 2, 3, 4, 5}; 
  std::vector<int> v2; 
  std::vector<int> v3; 

  v2 = v1; 
  std::cout << v1.size() << std::endl;  // 输出 5
  std::cout << v2.size() << std::endl;  // 输出 5

  v3 = std::move(v1); // move
  std::cout << v1.size() << std::endl;  // 输出0
  std::cout << v3.size() << std::endl;  // 输出 5
 
}

void two() {
  std::vector<int> v(1024);

  std::cout << "================ Copy =======================" << std::endl;
  Foo cf1("hello", v);
  Foo cf2(cf1);  // 调用拷贝构造函数
  Foo cf3;
  cf3 = cf2;  // 调用拷贝赋值操作符
  
  std::cout << "================ Move =========================" << std::endl;
  Foo f1("hello", v);
  Foo f2(std::move(f1));  // 调用移动构造函数
  Foo f3;
  f3 = std::move(f2);  // 调用移动赋值操作符
}


Foo GetFoo() {
  return Foo("GetFoo", std::vector<int>(11));
}

void three() {
  std::vector<int> v3(3);
  Foo f3("world", v3);
  f3 = GetFoo(); // GetFoo 返回的是一个右值，调用移动赋值操作符
}

void four() {
  // Foo f3;
  // f3 = GetFoo();

  // LogAndProcessNotForward<Foo>(GetFoo());                         // 输出 lvalue reference
  // LogAndProcessNotForward<Foo>(std::move(GetFoo()));  // 输出 lvalue reference
  // LogAndProcessNotForward<Foo>(std::move(GetFoo()));  // 输出 lvalue reference

  // LogAndProcessWithForward(GetFoo());                        // 输出 lvalue reference
  // LogAndProcessWithForward(std::move(GetFoo()));  // 输出 rvalue reference
}

int main() {
  three();
  return 0; 
}