#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class person {
  private:
    int no;
  public:
    person(int no_=0):no(no_) { cout << "constructing a person" << endl; }
    ~person() { cout << "destroying a person" << endl; }
    person(const person& rhs) {
      cout << "copying a person" << endl;
    }
    person& operator=(const person& rhs) {
      cout << "assigning a person" << endl;
    }
    void increase() {
      no++;
    }
    int number() {
      return no;
    }
};

void verify1() {
  vector<person> vec;
  person yao;
  vec.push_back(yao);
  cout << "before pop_back" << endl;
  vec.pop_back();
  cout << "after pop_back" << endl;
}

void test1() {
  cout << "======= test1 begin" << endl;
  verify1();
  cout << "------- test1 end" << endl << endl;;
}

void test2() {
  cout << "======= test2 begin" << endl;
  vector<person> vec;
  person yao;
  vec.push_back(yao);
  cout << "before back" << endl;
  person alias = vec.back();
  cout << "after back" << endl;
  alias.increase();
  assert(vec.back().number() == 0);
  cout << "------- test2 end" << endl << endl;;
}

void test3() {
  cout << "======= test3 begin" << endl;
  vector<person> vec;
  person yao;
  vec.push_back(yao);
  cout << "before back" << endl;
  person& alias = vec.back();
  cout << "after back" << endl;
  alias.increase();
  assert(vec.back().number() == 1);
  cout << "------- test3 end" << endl << endl;;
}

int main(int argc, const char *argv[]) 
{
  test1();
  test2();
  test3();
  return 0;
}
