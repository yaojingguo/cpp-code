#include <iostream>
#include <vector>

using namespace std;

template<class IterT>
struct my_iterator_traits {
  typedef typename IterT::value_type value_type;
};

template<class IterT>
struct my_iterator_traits<IterT*> {
  typedef IterT value_type;
};

void fun(int a) {
    cout << "fun(int) is called" << endl;
}
void fun(double a) {
    cout << "fun(double) is called" << endl;
}
void fun(char a) {
    cout << "fun(char) is called" << endl;
}

int main(int argc, char const *argv[]) {
  my_iterator_traits<vector<int>::iterator>::value_type a;
  fun(a);  // 输出 fun(int) is called

  my_iterator_traits<vector<double>::iterator>::value_type b;
  fun(b);  // 输出 fun(double) is called

  my_iterator_traits<char*>::value_type c;
  fun(c);  // 输出 fun(char) is called
  return 0;
}
