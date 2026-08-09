#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;

    void display()
    {
        cout << "Area = " << area() << endl;
        cout << "Perimeter = " << perimeter() << endl;
    }
};

class Circle : public Shape
{
    float r;

public:
    Circle(float radius)
    {
        r = radius;
    }

    float area()
    {
        return 3.1416 * r * r;
    }

    float perimeter()
    {
        return 2 * 3.1416 * r;
    }
};

class Rectangle : public Shape
{
    float l, b;

public:
    Rectangle(float length, float breadth)
    {
        l = length;
        b = breadth;
    }

    float area()
    {
        return l * b;
    }

    float perimeter()
    {
        return 2 * (l + b);
    }
};

class Triangle : public Shape
{
    float a, b, c;

public:
    Triangle(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
    }

    float area()
    {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    float perimeter()
    {
        return a + b + c;
    }
};

int main()
{
    // Shape s;

    Shape *ptr;

    Circle c(5);
    Rectangle r(10, 4);
    Triangle t(3, 4, 5);

    ptr = &c;
    cout << "Circle" << endl;
    ptr->display();

    cout << endl;

    ptr = &r;
    cout << "Rectangle" << endl;
    ptr->display();

    cout << endl;

    ptr = &t;
    cout << "Triangle" << endl;
    ptr->display();

    return 0;
}
