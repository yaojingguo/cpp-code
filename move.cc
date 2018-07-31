#include <utility>
#include <stdio.h>
#include <string.h>

template<class T>
void swap(T& a, T& b)
{
  T tmp{ std::move(a) }; // invokes move constructor
  printf("++++++++++++++++++++\n");
  a = std::move(b); // invokes move assignment
  printf("====================\n");
  b = std::move(tmp); // invokes move assignment
}

class A {
  public:
    A(const char* data, int size): data_(data), size_(size) {
      printf("construct A\n");
    }
    A(const A& a) {
      printf("copy construct A\n");
      data_ = new char[a.size_];
      memcpy((void*)data_, (void*)a.data_, size_);
      size_ = a.size_;
    }
    A(A&& a) {
      printf("move constructing A\n");
      data_ = a.data_;
      size_ = a.size_;

      a.data_ = nullptr;
      a.size_ = 0;
    }
    A& operator=(A&& a) {
      printf("move assignment A\n");
      data_ = a.data_;
      size_ = a.size_;

      a.data_ = nullptr;
      a.size_ = 0;
      return *this;
    }
  private:
    const char * data_;
    int size_;
};

int main() {
  A a1("abc", 4);
  A a2("def", 4);
  printf("------------------\n");
  swap(a1, a2);
}

