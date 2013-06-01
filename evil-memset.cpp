#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

struct res {
  int no;
  string name;
};

void test9() {
  res r;
  r.no = 100;
  r.name.append("abc");
  printf("no: %d, name: %s\n", r.no, r.name.c_str());
  memset(&r, 0, sizeof(r));
  r.name.append("def"); // Trigger segmentation fault
}

int main(int argc, const char *argv[]) 
{
  test9();
  return 0;
}
