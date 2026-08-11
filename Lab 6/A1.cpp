#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
private:
    string color;

public:
    Shape(string c) : color(c) {}

    string getColor() const { return color; }

    virtual float area() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(string c, float r) : Shape(c), radius(r) {}

    float area() const override {
        return 3.14159f * radius * radius;
    }

    void display() const {
        cout << "Circle [Color: " << getColor() << ", Area: " << area() << "]" << endl;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(string c, float l, float w) : Shape(c), length(l), width(w) {}

    float area() const override {
        return length * width;
    }

    void display() const {
        cout << "Rectangle [Color: " << getColor() << ", Area: " << area() << "]" << endl;
    }
};

class Triangle : public Shape {
private:
    float base, height;

public:
    Triangle(string c, float b, float h) : Shape(c), base(b), height(h) {}

    float area() const override {
        return 0.5f * base * height;
    }

    void display() const {
        cout << "Triangle [Color: " << getColor() << ", Area: " << area() << "]" << endl;
    }
};

int main() {
    Circle c("Red", 5.0f);
    Rectangle r("Blue", 4.0f, 6.0f);
    Triangle t("Green", 3.0f, 8.0f);

    c.display();
    r.display();
    t.display();

    return 0;
}