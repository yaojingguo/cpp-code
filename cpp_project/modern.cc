#include <memory>
#include <vector>
#include <string>

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

int main(int argc, char const *argv[])
{
  vector<string> apples;
  apples.push_back("Pine Apple");
  return 0;
}
