#include <iostream>
using namespace std;
class Box {
    float l, b, h;
public:
    Box() {
        l = b = h = 0;
        cout << "Default constructor called\n";
    }
    Box(float x, float y = 1, float z = 1) {
        l = x;
        b = y;
        h = z;
        cout << "Constructor with default arguments called\n";
    }
    Box(const Box &obj) {
        l = obj.l;
        b = obj.b;
        h = obj.h;
        cout << "Copy constructor called\n";
    }
    ~Box() {
        cout << "Destructor called for Box\n";
    }
};
int main() {
    Box b1;         
    Box b2(2, 3, 4); 
    Box b3(5);      
    Box b4 = b2;   
    return 0;
}