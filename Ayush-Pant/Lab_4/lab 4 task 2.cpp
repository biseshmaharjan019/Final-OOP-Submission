#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r = 0) {
        radius = r;
    }

    float getArea() const {
        return 3.1416 * radius * radius;
    }

    float getCircumference() const {
        return 2 * 3.1416 * radius;
    }

    void display() const {
        cout << "Radius = " << radius << endl;
        cout << "Area = " << getArea() << endl;
        cout << "Circumference = "
             << getCircumference() << endl;
    }

    void setRadius(float r) {
        radius = r;
    }
};

int main() {
    Circle c1(5);
    const Circle c2(10);

    c1.display();
    c1.setRadius(8);      // Allowed

    cout << "\nConst Circle:\n";
    c2.display();         // Allowed

    // c2.setRadius(15);
    // Not allowed because c2 is const and
    // setRadius() is a non-const function.

    return 0;
}
