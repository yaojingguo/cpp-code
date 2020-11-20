// C++ program to illustrate the placement new operator 
#include<iostream> 
using namespace std; 

int main() 
{ 
  // initial value of X 
  int X = 10; 

  cout << "Before placement new :" << endl; 
  cout << "X : " << X << endl; 
  cout << "&X : " << &X << endl; 

  // Placement new changes the value of X to 100 
  int *mem = new (&X) int(100); 

  cout << "\nAfter placement new :" << endl; 
  cout << "X : " << X << endl; 
  cout << "mem : " << mem << endl; 
  cout << "&X : " << &X << endl; 

  return 0; 
} 
