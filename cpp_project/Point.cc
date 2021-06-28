#include <iostream>
#include <utility>

class A {
 public:
  A():pointer(new int(1)) { 
    std::cout << "constructing " << pointer << std::endl; 
  }
  A(A& a):pointer(new int(*a.pointer)) { 
    std::cout << "copy constructing " << pointer << std::endl; 
  } 
  A(A&& a):pointer(a.pointer) { 
    a.pointer = nullptr;
    std::cout << "moving constructing " << pointer << std::endl; 
  }
  ~A(){ 
    std::cout << "destructing " << pointer << std::endl; 
    delete pointer; 
  }
  int *pointer;
};

// 防止编译器优化
A return_rvalue(bool test) {
  A a,b;
  if(test) return a; // 等价于 static_cast<A&&>(a);
  else return b;     // 等价于 static_cast<A&&>(b);
}

// void by_move(A&& a) {
//   std::cout << "move function" << std::endl;
// }

// void by_move(A& a) {
//   std::cout << "copy function" << std::endl;
// }

int main() {
  A obj = return_rvalue(false);
  std::cout << "obj:" << std::endl;
  std::cout << "  " << obj.pointer << std::endl;
  std::cout << "  " << *obj.pointer << std::endl;
  return 0;
}
