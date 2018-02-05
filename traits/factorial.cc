#include <iostream>

template <int N>
struct Factorial {
     enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> {
    enum { value = 1 };
};

// Factorial<4>::value == 24
// Factorial<0>::value == 1
int main()
{
    int x = Factorial<4>::value;
    std::cout << "4! = " << x << std::endl;

    int y = Factorial<0>::value;
    std::cout << "0! = " << y << std::endl;
}
