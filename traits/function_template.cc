#include <string>
#include <iostream>

// legal: base function template
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType arg);

// legal: explicit/full function template specialization
template <>
std::string Foo<std::string, char>(char arg) { return "Full\n"; }

// illegal: partial function template specialization of the return type
//          function template partial specialization is not allowed
// template <typename ArgumentType>
// void Foo<void, ArgumentType>(ArgumentType arg);

// legal: overloads the base template for a pointer argument type
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType *argPtr) { return "PtrOverload\n"; }

// legal: base function name reused. Not considered an overload. ill-formed: non-overloadable declaration (see below)
template <typename ArgumentType>
std::string Foo(ArgumentType arg) { return "Return1\n"; }

// legal: base function name reused. Not considered an overload. ill-formed: non-overloadable declaration (see below)
template <typename ReturnType>
ReturnType Foo(char arg) { return "Return2\n"; }

// note: to be compiled in conjunction with the definitions of Foo above
int main(int argc, char *argv[]) {
    char c = 'c';
    std::string r0, r1, r2, r3;

    // let the compiler resolve the call
    r0 = Foo(c);
    // explicitly specify which function to call
    r1 = Foo<std::string>(c);       //
    r2 = Foo<std::string, char>(c); // Full
    r3 = Foo<std::string, char>(&c); // Pointer

    // generate output
    std::cout << r0 << " " << r1 << " " << r2 << " " << r3 << std::endl;
    return 0;
}
