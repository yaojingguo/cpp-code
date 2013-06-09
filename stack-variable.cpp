#include <iostream>

using namespace std;

class person {
  private:
    int no;
  public:
    person(int);
    void info();
};
person::person(int no_=0):no(no_) {
}
void person::info() {
  cout << "hi: " << no << endl;
}

person* ref;

void test1() {
  person p;
  ref = &p;
}

int main(int argc, const char *argv[]) 
{
  test1();  
  ref->info(); // Print garbage value
  return 0;
}
