// cast-reference.cpp
// Compile with: /EHsc
#include <iostream>
#include <utility>

using namespace std;

// A class that contains a memory resource.
class MemoryBlock {
   // TODO: Add resources for the class here.
   public:
   void info() {
     cout << "I am a memory block" << endl;
   }
};

void g(const MemoryBlock&) {
   cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&) {
   cout << "In g(MemoryBlock&&)." << endl;
}

int main() {
   MemoryBlock block;
   g(block);
   g(static_cast<MemoryBlock&&>(block));
   g(std::move(block));
   block.info();
}