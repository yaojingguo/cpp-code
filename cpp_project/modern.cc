#include <memory>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Widget
{
public:
Widget(const int size) {
  data = std::make_unique<int>(size);
}
void do_something() {

}
private:
  std::unique_ptr<int> data;
};

void functionUsingWidget() {
  Widget w(100);
  w.do_something();
}

void vector_usage() {
  vector<string> apples;
  apples.push_back("Pine Apple");
}

void map_usage() {
  map<string, string> apple_color;
  apple_color["Pine Apple"] = "Green";
}

void multimap_usage() {
  cout << "mulitmap usage" << endl;
  multimap<int, int> nums1{{10, 1}, {2, 3}};
  for (auto const &x: nums1) {
    cout << x.first << ": " << x.second << endl;
  }
}

void multiset_usage() {
  cout << "multiset usage" << endl;
  multiset<int> mset{1, 2, 10, 0, 10, 5, 10};
  for (int x: mset) {
    cout << x << endl;
  }
}

void comp_usage() {
  auto comp = [](const int v1, const int v2) 
  {
    return v1 < v2;
  };
  vector<int> vec{1, 10, 0};
  sort(vec.begin(), vec.end(), comp);
  
  cout << "sorted vector" << endl;
  for (int no: vec) {
    cout << no << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
  multimap_usage();
  multiset_usage();
  comp_usage();
  return 0;
}
