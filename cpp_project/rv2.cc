// named-reference.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock {
   // TODO: Add resources for the class here.
};

void g(const MemoryBlock&) {
   cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&) {
   cout << "In g(MemoryBlock&&)." << endl;
}

MemoryBlock&& f(MemoryBlock&& block) {
   g(block);
   return move(block);
}

int main() {
   g(f(MemoryBlock()));
}