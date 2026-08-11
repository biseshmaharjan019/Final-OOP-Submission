#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float getArea() const {
        return 3.14159 * radius * radius;
    }

    float getCircumference() const {
        return 2 * 3.14159 * radius;
    }

    void display() const {
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumference() << endl;
    }

    void setRadius(float r) {
        radius = r;
    }
};

int main() {
    Circle c1(5);
    const Circle c2(10);

    cout << "Normal Circle:" << endl;
    c1.display();
    cout << "Area: " << c1.getArea() << endl;
    cout << "Circumference: " << c1.getCircumference() << endl;
    c1.setRadius(7);

    cout << "\nConst Circle:" << endl;
    c2.display();
    cout << "Area: " << c2.getArea() << endl;
    cout << "Circumference: " << c2.getCircumference() << endl;

    // c2.setRadius(15); // Not allowed because setRadius() is non-const.

    system("pause");
    return 0;
}
