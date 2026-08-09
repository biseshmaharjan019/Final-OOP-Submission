#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float area() const = 0;
    virtual float perimeter() const = 0;

    void display() const {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float area() const override {
        return 3.14159f * radius * radius;
    }

    float perimeter() const override {
        return 2 * 3.14159f * radius;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float area() const override {
        return length * width;
    }

    float perimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    float a, b, c;

public:
    Triangle(float sideA, float sideB, float sideC) {
        a = sideA;
        b = sideB;
        c = sideC;
    }

    float perimeter() const override {
        return a + b + c;
    }

    float area() const override {
        float s = perimeter() / 2.0f;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    // Shape s; 
    // The line above is disabled because Shape is an abstract class 
    // due to its pure virtual functions and cannot be instantiated directly.

    Circle circle(5.0f);
    Rectangle rectangle(4.0f, 6.0f);
    Triangle triangle(3.0f, 4.0f, 5.0f);

    Shape* shapePtr = nullptr;

    cout << "Circle Details" << endl;
    shapePtr = &circle;
    shapePtr->display();

    cout << "\nRectangle Details" << endl;
    shapePtr = &rectangle;
    shapePtr->display();

    cout << "\nTriangle Details" << endl;
    shapePtr = &triangle;
    shapePtr->display();

    return 0;
}
