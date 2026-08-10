/*
Question 2:
Write a program with a class Circle having private member radius.
Write const member functions getArea(), getCircumference(), and display().
Write a non-const function setRadius().
Create a normal Circle object and a const Circle object.
Show which functions can be called on each object and explain why some calls are not allowed.
*/

#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void setRadius(float r) {
        radius = r;
    }

    float getArea() const {
        return 3.1416 * radius * radius;
    }

    float getCircumference() const {
        return 2 * 3.1416 * radius;
    }

    void display() const {
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumference() << endl;
    }
};

int main() {
    Circle c1(5);
    const Circle c2(7);

    cout << "Normal Circle:" << endl;
    c1.display();
    c1.setRadius(10);
    c1.display();

    cout << "\nConstant Circle:" << endl;
    c2.display();

    // c2.setRadius(12);
    // This is not allowed because c2 is a const object.
    // A const object can only call const member functions.

    return 0;
}