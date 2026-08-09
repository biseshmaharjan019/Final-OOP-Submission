// Write a program with a class Circle having private member radius.Write constant member 
// function getArea() ,getCircumference and display(). Write a non constant on setRadius().
// In main, create a normal circle object and a constant circle object.Show which function can be
//  called an each object and explain in a comment why certain calls are not allowed on the constant
//   object
#include <iostream>
using namespace std;

class Circle {
private:
    float r;

public:
    Circle(float r1 = 0) {
        r = r1;
    }

    void setRadius(float x) {
        r = x;
    }

    float getArea() const {
        return 3.1416 * r * r;
    }

    float getCircumference() const {
        return 2 * 3.1416 * r;
    }

    void display() const {
        cout << "Radius: " << r << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumference() << endl;
    }
};

int main() {
    Circle c1(5);
    const Circle c2(3);

    c1.display();
    c1.setRadius(7);

    c2.display();
    cout << c2.getArea() << endl;
    cout << c2.getCircumference() << endl;

    return 0;
}