#include <iostream>
#include <cmath>

class Shape {
public:
    virtual float area() const = 0;
    virtual float perimeter() const = 0;

    virtual void display() const {
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    float area() const override {
        return 3.14159f * radius * radius;
    }

    float perimeter() const override {
        return 2.0f * 3.14159f * radius;
    }
};

class Rectangle : public Shape {
private:
    float width;
    float height;

public:
    Rectangle(float w, float h) : width(w), height(h) {}

    float area() const override {
        return width * height;
    }

    float perimeter() const override {
        return 2.0f * (width + height);
    }
};

class Triangle : public Shape {
private:
    float a, b, c;

public:
    Triangle(float s1, float s2, float s3) : a(s1), b(s2), c(s3) {}

    float area() const override {
        float s = (a + b + c) / 2.0f;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    float perimeter() const override {
        return a + b + c;
    }
};

int main() {
    

    Circle c(5.0f);
    Rectangle r(4.0f, 6.0f);
    Triangle t(3.0f, 4.0f, 5.0f);

    Shape* shapePtr = nullptr;

    std::cout << "=== Circle ===" << std::endl;
    shapePtr = &c;
    shapePtr->display();

    std::cout << "\n=== Rectangle ===" << std::endl;
    shapePtr = &r;
    shapePtr->display();

    std::cout << "\n=== Triangle ===" << std::endl;
    shapePtr = &t;
    shapePtr->display();

    return 0;
}