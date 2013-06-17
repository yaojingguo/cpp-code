#include <iostream>
using namespace std;

template<typename _Arg1, typename _Arg2, typename _Result>
struct bin_func 
{
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;
};

template<typename _Tp>
struct small: public bin_func<_Tp, _Tp, bool>
{
  bool operator()(const _Tp& __x, const _Tp& __y) const 
  {
    return __x < __y;
  }
};

void test1()
{
  int x = 11;
  int y = 23;
  cout << small<int>()(x, y) << endl;
  cout << small<int>()(10, 1) << endl;
}

struct Compare : public std::binary_function<int, int, bool> {
  bool operator()(int a, int b) {return (a==b);}
};

void test2()
{
  Compare Compare_object;
  Compare::first_argument_type input1;
  Compare::second_argument_type input2;
  Compare::result_type result;

  input1 = 10;
  input2 = 9;

  result = Compare_object(input1,input2);

  std::cout << "Numbers " << input1 << " and " << input2;
  if (result)
    std::cout << " are equal.\n";
  else
    std::cout << " are not equal.\n";
}

int main () {
  test1();
  test2();
}
