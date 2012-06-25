#include <iostream>

using namespace std;

template<int A, int B>
struct static_max
{
	static const int value = A > B ? A : B;
};


int main(int argc, const char *argv[]) {
	int max_value;

	// Run g++ -S produces:
	// ...
	// movl	$4, -4(%ebp)
	// addl	$99, -4(%ebp)
	// ...
	max_value= static_max<sizeof(int), sizeof(short)>::value;
	max_value += 99;
		
	return 0;
}
