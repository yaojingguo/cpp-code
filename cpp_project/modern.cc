#include <memory>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>
#include <variant>

using namespace std;

class Widget
{
public:
  Widget(const int size)
  {
    data = std::make_unique<int>(size);
  }
  void do_something()
  {
  }

private:
  std::unique_ptr<int> data;
};

void functionUsingWidget()
{
  Widget w(100);
  w.do_something();
}

void vector_usage()
{
  vector<string> apples;
  apples.push_back("Pine Apple");
}

void map_usage()
{
  map<string, string> apple_color;
  apple_color["Pine Apple"] = "Green";
}

void multimap_usage()
{
  cout << "mulitmap usage" << endl;
  multimap<int, int> nums1{{10, 1}, {2, 3}};
  for (auto const &x : nums1)
  {
    cout << x.first << ": " << x.second << endl;
  }
}

void multiset_usage()
{
  cout << "multiset usage" << endl;
  multiset<int> mset{1, 2, 10, 0, 10, 5, 10};
  for (int x : mset)
  {
    cout << x << endl;
  }
}

void comp_usage()
{
  auto comp = [](const int v1, const int v2)
  {
    return v1 < v2;
  };
  vector<int> vec{1, 10, 0};
  sort(vec.begin(), vec.end(), comp);

  cout << "sorted vector" << endl;
  for (int no : vec)
  {
    cout << no << " ";
  }
  cout << endl;
}

struct S
{
  std::string name;
  float num;
  S(std::string s, float f) : name(s), num(f) {}
};

void uniform_initialization_usage()
{
  vector<S> v;
  S s1("North", 2.7);
  S s2("Frank", 3.5);
  S s3("Jeri", 85.9);

  v.push_back(s1);
  v.push_back(s2);
  v.push_back(s3);

  vector<S> v2{s1, s2, s3};

  std::vector<S> v3{{"Norah", 2.7}, {"Frank", 3.5}, {"Jeri", 85.9}};
}

void lambda_usage() {
  vector<int> v{1, 2, 3, 4, 5};
  int x = 2;
  int y = 4;
  auto result = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });
}

int main()
{
  multimap_usage();
  multiset_usage();
  comp_usage();
  return 0;
}
