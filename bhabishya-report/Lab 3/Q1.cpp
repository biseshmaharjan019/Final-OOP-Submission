#include <iostream>
using namespace std;

class Box {
private:
    float l, b, h;

public:
    // Default constructor
    Box() {
        l = b = h = 0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor with default arguments
    Box(float length, float breadth = 1, float height = 1) {
        l = length;
        b = breadth;
        h = height;
        cout << "Constructor with default arguments called." << endl;
    }

    // Copy constructor
    Box(const Box &obj) {
        l = obj.l;
        b = obj.b;
        h = obj.h;
        cout << "Copy constructor called." << endl;
    }

    // Destructor
    ~Box() {
        cout << "Destructor called. Object destroyed." << endl;
    }
};

int main() {
    Box b1;
    Box b2(2, 3, 4);
    Box b3(5, 6);
    Box b4(b2);

    system("pause");
    return 0;
}