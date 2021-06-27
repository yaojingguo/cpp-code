#include <vector>

#include "MemoryBlock.h"
#include "Point.h"
#include "foo.h"

using namespace std;

int two() {
  std::string str = "Hello";
  std::vector<std::string> v;

  v.push_back(str);
  std::cout << "After copy, str is \"" << str << std::endl;

  v.push_back(std::move(str));
  std::cout << "After move, str is \"" << str << std::endl;

  for (auto s: v) {
    std::cout << "  " << s << std::endl;
  }
}


Foo GetFoo() {
  return Foo("GetFoo", std::vector<int>(11));
}
