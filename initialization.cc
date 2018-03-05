#include <iostream>
#include <vector>
#include <iterator>
#include <stdio.h>

using namespace std;

class Point {
public:
  Point(int x, int y): _x{x}, _y{y} {
    cout << "constructing (" << _x << ", " << _y << ")\n";
  }
private:
  int _x;
  int _y;
};

struct King {
  int no;
  int age;
};

void draw(Point p) {
  cout << "drawing point\n";
}

void test1() {
  vector<int> v = {3, 1, 4};
  auto vi = begin(v);
  cout << *vi << endl;

  int a[] = {-5, 10, 15};
  auto ai = begin(a);
  cout << *ai << endl;
}

int main(int argc, char const *argv[]) {
  draw({10, 100});
  Point p{1, 1};

  King k{1, 100};
  printf("king: no=%d, age=%d\n", k.no, k.age);

  return 0;
}
