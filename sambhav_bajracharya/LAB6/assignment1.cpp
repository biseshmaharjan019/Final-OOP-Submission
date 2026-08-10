#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
    string color;

public:
    Shape(string c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    virtual float area() const = 0;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(string c, float r) : Shape(c) {
        radius = r;
    }

    float area() const override {
        return 3.14159f * radius * radius;
    }

    void display() const {
        cout << "Shape: Circle" << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Area: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(string c, float l, float w) : Shape(c) {
        length = l;
        width = w;
    }

    float area() const override {
        return length * width;
    }

    void display() const {
        cout << "Shape: Rectangle" << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Area: " << area() << endl;
    }
};

class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(string c, float b, float h) : Shape(c) {
        base = b;
        height = h;
    }

    float area() const override {
        return 0.5f * base * height;
    }

    void display() const {
        cout << "Shape: Triangle" << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Area: " << area() << endl;
    }
};

int main() {
    Circle circ("Red", 5.0f);
    Rectangle rect("Blue", 4.0f, 6.0f);
    Triangle tri("Green", 3.0f, 8.0f);

    cout << "Circle" << endl;
    circ.display();

    cout << "\nRectangle" << endl;
    rect.display();

    cout << "\nTriangle" << endl;
    tri.display();

    return 0;
}
