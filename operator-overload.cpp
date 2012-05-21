#include <iostream>
#include <ostream>

using namespace std;

class Foo {
	public:
		Foo(int n) : _n(n) {}
		Foo & operator+(const Foo &rhs);
		int get_n() {
			return _n;
		}
	private:
		int _n;
};

// Global operator overloading
ostream& operator << (ostream& os, Foo& o) {
	os << o.get_n();
	return os;
}

// Class operator overloading
Foo & Foo::operator+(const Foo &rhs) {
	this->_n += rhs._n;
	return *this;
}

int main(int argc, const char *argv[]) {
	// c-style initialization
	Foo one(1), two(2);
	// Constructor initialization
 	Foo three = 9;
	three = one + two;
	cout << three << endl;
	return 0;
}
