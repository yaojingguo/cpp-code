#include <string>

// legal: base function template
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType arg);

// legal: explicit/full function template specialization
template <>
std::string Foo<std::string, char>(char arg) {
  return "Full";
}

int main(int argc, char const *argv[]) {

  return 0;
}
