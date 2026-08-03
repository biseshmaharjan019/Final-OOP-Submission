// Q1. Write a program with a class Box having private data members l, b, h.
// Demonstrate default constructor, parameterized constructor,
// constructor with default arguments, copy constructor, and destructor.

#include <iostream>
using namespace std;

class Box {
private:
    float l, b, h;

public:
    Box() {
        l = b = h = 0;
        cout << "Default constructor called" << endl;
    }

    Box(float length, float breadth, float height) {
        l = length;
        b = breadth;
        h = height;
        cout << "Parameterized constructor called" << endl;
    }

    Box(float length, float breadth = 1) {
        l = length;
        b = breadth;
        h = 1;
        cout << "Constructor with default arguments called" << endl;
    }

    Box(const Box &obj) {
        l = obj.l;
        b = obj.b;
        h = obj.h;
        cout << "Copy constructor called" << endl;
    }

    void display() {
        cout << "Length: " << l << ", Breadth: " << b << ", Height: " << h << endl;
    }

    ~Box() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Box b1;
    Box b2(2, 3, 4);
    Box b3(5);
    Box b4(b2);

    b1.display();
    b2.display();
    b3.display();
    b4.display();

    return 0;
}