#include <iostream>
#include <map>

using namespace std;

struct key {
  int no;
  bool operator<(const key& rhs) const {
    return no < rhs.no ? true : false;
  }
};

struct obj {
  int no;
};

struct obj_cmp {
  bool operator()(const obj& lhs, const obj& rhs) const {
    return lhs.no < rhs.no ? true : false;
  }
};

void test1() {
  map<obj, int, obj_cmp> m;
  obj o = {1};
  m[o] = 100;
}

void test2() {
  map<key, int> m;
  key k1 = {3};
  key k2 = {1};
  key k3 = {2};
  m[k1] = 300;
  m[k2] = 100;
  m[k3] = 200;
  for (map<key, int>::iterator it = m.begin(); it != m.end(); ++it) 
    cout << it->first.no << ":" << it->second << endl;
}

int main () {
  test1();
  test2();
}
