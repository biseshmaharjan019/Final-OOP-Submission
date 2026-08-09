#include <iostream>
using namespace std;
class Shape {
private:
    string color;
public:
    Shape(string c) {
        color = c;
    }
    string getColor() {
        return color;
    }

    virtual float area() = 0;
};
class Circle : public Shape {
private:
    float radius;
public:
    Circle(string c, float r)
        : Shape(c) {
        radius = r;
    }
    float area() {
        return 3.14159f * radius * radius;
    }
    void display() {
        cout << "Color: " << getColor() << endl;
        cout << "Area: " << area() << endl;
    }
};
class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(string c, float l, float w)
        : Shape(c) {
        length = l;
        width = w;
    }
    float area() {
        return length * width;
    }
    void display() {
        cout << "Color: " << getColor() << endl;
        cout << "Area: " << area() << endl;
    }
};
class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(string c, float b, float h)
        : Shape(c) {
        base = b;
        height = h;
    }
    float area() {
        return 0.5f * base * height;
    }
    void display() {
        cout << "Color: " << getColor() << endl;
        cout << "Area: " << area() << endl;
    }
};
int main() {
    Circle c("Red", 5);
    Rectangle r("Blue", 6, 4);
    Triangle t("Green", 8, 5);
    c.display();
    cout << endl;
    r.display();
    cout << endl;
    t.display();
    return 0;
}
