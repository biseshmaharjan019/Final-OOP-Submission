#include <iostream>
using namespace std;
class Circle {
private:
    float radius;
public:
    Circle(float r = 0) {
        radius = r;
    }
void setRadius(float r) {
        radius = r;
    }
float getArea() const {
        return 3.14 * radius * radius;
    }
float getCircumference() const {
        return 2 * 3.14 * radius;
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
c1.setRadius(10);
c1.display();
    cout << c1.getArea() << endl;
    cout<<c1.getCircumference()<<endl;
c2.display();
    cout << c2.getArea() << endl;
    cout << c2.getCircumference() << endl;

    return 0;
}
