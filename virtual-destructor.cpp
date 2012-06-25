#include <iostream>

using namespace std;

class Shape {
	public:
		Shape() {
			cout << "Construct a shape" << endl;
		}
		virtual ~Shape() {
			cout << "Destruct a shape" << endl;
		}
};

class Circle : public Shape {
	public:
		Circle() {
			cout << "Construct a circle" << endl;
		}
		~Circle() {
			cout << "Destruct a circle" << endl;
		}
};

int main(int argc, const char *argv[]) {
	Shape* one = new Circle();	
	delete one;
	return 0;
}
