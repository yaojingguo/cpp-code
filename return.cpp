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

Point returnReference(int x, int y) {
}

int main() 
{ 
    Point value = returnValue(100, 200);
    cout << "\nresult: x = " << value.getX() << ", y = " << value.getY() << endl;

    return 0; 
}

