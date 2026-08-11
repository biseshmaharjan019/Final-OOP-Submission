#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;

    virtual void display() {
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
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
        return 2.0f * 3.14159f * radius;
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
        return 2.0f * (length + width);
    }
};

class Triangle : public Shape {
private:
    float a, b, c;

public:
    Triangle(float s1, float s2, float s3) : a(s1), b(s2), c(s3) {}

    float perimeter() override {
        return a + b + c;
    }

    float area() override {
        float s = perimeter() / 2.0f;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    // Attempting to instantiate an abstract class directly is illegal:
    // Shape testShape; // Error: cannot instantiate abstract class 'Shape' due to pure virtual functions

    Circle circleObj(5.0f);
    Rectangle rectObj(4.0f, 6.0f);
    Triangle triObj(3.0f, 4.0f, 5.0f);

    Shape* ptr = nullptr;

    cout << "--- Circle ---" << endl;
    ptr = &circleObj;
    ptr->display();

    cout << "\n--- Rectangle ---" << endl;
    ptr = &rectObj;
    ptr->display();

    cout << "\n--- Triangle ---" << endl;
    ptr = &triObj;
    ptr->display();

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}