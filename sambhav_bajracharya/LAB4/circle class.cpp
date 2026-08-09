#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r = 0.0) {
        radius = r;
    }

    void setRadius(double r) {
        radius = r;
    }

    double getArea() const {
        return 3.14159 * radius * radius;
    }

    double getCircumference() const {
        return 2 * 3.14159 * radius;
    }

    void display() const {
        cout << "Radius: " << radius << endl;
    }
};

int main() {
    Circle c1(7.0);
    const Circle c2(12.0);

    cout << "Normal Object (c1):" << endl;
    c1.display();
    cout << "Area: " << c1.getArea() << endl;
    cout << "Circumference: " << c1.getCircumference() << endl;

    c1.setRadius(10.0);
    cout << "Updated Normal Object Radius:" << endl;
    c1.display();

    cout << "\nConst Object (c2):" << endl;
    c2.display();
    cout << "Area: " << c2.getArea() << endl;
    cout << "Circumference: " << c2.getCircumference() << endl;

    // c2.setRadius(15.0); 
    // The line above is disabled because calling setRadius() on the const object 'c2' 
    // causes a compilation error. Const objects promise that their state won't change, 
    // so C++ prevents calling non-const methods on them.

    return 0;
}
