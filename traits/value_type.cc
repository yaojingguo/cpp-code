#include <iostream>
#include <vector>

template<typename T>
struct my_is_void {
  static const bool value = false;
};

template<>
struct my_is_void<void> {
  static const bool value = true;
};

void one() {
  my_is_void<bool> t1;
  std::cout << t1.value << std::endl;

  my_is_void<void> t2;
  std::cout << t2.value << std::endl;
}

template<typename T>
typename T::value_type top(const T &c)
{
  if (!c.empty())
    return c.back();
  else
    return typename T::value_type();
}

void two() {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  std::cout << top<std::vector<int>>(vec) << std::endl;
}


int main(int argc, char const *argv[]) {
  two();
  return 0;
}
