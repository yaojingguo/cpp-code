#include <iostream>
#include <ostream>

class Foo {
	private:
		int _n;

	public:
		// explicit disable implicit type conversion
		// explicit 
		Foo(int n) : _n(n) {}
		int getN() { return _n; }
		// Implicit type conversion does not work for reference.
		void increment(Foo/*&*/ another) 
		{
			_n += another._n;
		}
};

int main(int argc, const char *argv[]) {
	Foo i(10), a(100);
	i.increment(a);
	i.increment(9);
	return 0;
}
