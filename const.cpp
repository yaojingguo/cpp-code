#include <iostream>
#include <string>

using namespace std;

void func(const string& param1)
{
  cout << param1 << endl;
  cout << param1.size() << endl;
  // The following statement causes a compile error since erase is a non-const 
  // method.
  // param1.erase(0, 2);
}

int main(int argc, const char *argv[]) 
{
  return 0;
}
