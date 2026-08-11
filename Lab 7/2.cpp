#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual void display() {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}
    float area() override {
        return 3.14159f * radius * radius;
    }
    float perimeter() override {
        return 2 * 3.14159f * radius;
    }
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float area() override {
        return length * width;
    }
    float perimeter() override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    float a, b, c;
public:
    Triangle(float side1, float side2, float side3) : a(side1), b(side2), c(side3) {}
    float area() override {
        float s = (a + b + c) / 2.0f;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    float perimeter() override {
        return a + b + c;
    }
};

int main() {
    Shape* ptr;

    Circle c(5.0f);
    Rectangle r(4.0f, 6.0f);
    Triangle t(3.0f, 4.0f, 5.0f);

    ptr = &c;
    cout << "--- Circle ---" << endl;
    ptr->display();

    ptr = &r;
    cout << "\n--- Rectangle ---" << endl;
    ptr->display();

    ptr = &t;
    cout << "\n--- Triangle ---" << endl;
    ptr->display();

    return 0;
}