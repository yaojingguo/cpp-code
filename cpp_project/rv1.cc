// reference-overload.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock
{
   // TODO: Add resources for the class here.
};

void f(const MemoryBlock&)
{
   cout << "In f(const MemoryBlock&). This version cannot modify the parameter." << endl;
}

void f(MemoryBlock&&)
{
   cout << "In f(MemoryBlock&&). This version can modify the parameter." << endl;
}

int main()
{
   MemoryBlock block;
   f(block);
   f(MemoryBlock());
}