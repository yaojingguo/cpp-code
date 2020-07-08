#include<iostream> 
using namespace std; 

class Point { 
    private: 
        int x, y; 
    public: 
        Point(int x1, int y1) { x = x1; y = y1; } 

        // Copy constructor 
        Point(const Point &p2) {
            cout << "copying...\n";
            x = p2.x; 
            y = p2.y; 
        } 

        int getX()            {  return x; } 
        int getY()            {  return y; } 
}; 

Point returnValue(int x, int y) {
    Point p(x, y);
    return p;
}

// Compiler gives the follownig warning:
//   warning: reference to stack memory associated with local variable 'p' returned [-Wreturn-stack-address]
Point& returnReference(int x, int y) {
    Point p(x, y);
    return p;
}

// Compiler gives the following warning:
//   warning: address of stack memory associated with local variable 'p' returned [-Wreturn-stack-address]
Point* returnPointer(int x, int y) {
    Point p(x, y);
    return &p;
}

int main() { 
    Point value = returnValue(100, 200);
    cout << "\nresult: x = " << value.getX() << ", y = " << value.getY() << endl;

    Point& reference = returnReference(100, 200);

    Point* pointer = returnPointer(100, 200);

    return 0; 
}

