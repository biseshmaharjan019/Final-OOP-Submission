#include <iostream>
#include <cmath>       
using namespace std;

class Shape {
public:

    virtual float area()      = 0;
    virtual float perimeter() = 0;

    
    
    virtual void display() {
        cout << "  Area      : " << area()      << endl;
        cout << "  Perimeter : " << perimeter() << endl;
    }

    virtual ~Shape() = default;   
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}

    float area() override {
        return static_cast<float>(M_PI) * radius * radius;
    }
    float perimeter() override {          
        return 2.0f * static_cast<float>(M_PI) * radius;
    }
};

class Rectangle : public Shape {
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
    float base, height, side1, side2;
public:
    
    Triangle(float b, float s1, float s2)
        : base(b), side1(s1), side2(s2) {
        
        float sp = (base + side1 + side2) / 2.0f;           
        height = 2.0f * sqrt(sp*(sp-base)*(sp-side1)*(sp-side2)) / base;
    }

    float area() override {
        return 0.5f * base * height;
    }
    float perimeter() override {
        return base + side1 + side2;
    }
};

int main() {
    
    Circle    c(5.0f);
    Rectangle r(4.0f, 6.0f);
    Triangle  t(3.0f, 4.0f, 5.0f);   

    Shape* ptr;   

    cout << "--- Circle (radius = 5) ---" << endl;
    ptr = &c;
    ptr->display();   

    cout << "--- Rectangle (4 x 6) ---" << endl;
    ptr = &r;
    ptr->display();   

    cout << "--- Triangle (sides 3, 4, 5) ---" << endl;
    ptr = &t;
    ptr->display();   

    return 0;
}