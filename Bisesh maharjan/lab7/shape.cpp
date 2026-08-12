#include <iostream>
#include <math.h>
using namespace std;
class Shape
{
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual void display()
    {
        
    }
};
class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    float area()
    {
        return length * breadth;
    }

    float perimeter()
    {
        return 2 * (length + breadth);
    }
    void display()
    {
        cout << "Area = " << area() << endl;
        cout << "Perimeter = " << perimeter() << endl;
    }
};
class Circle : public Shape
{
private:
    float radius;
public:
    Circle(float r)
    {
        radius = r;
    }
    float area()
    {
        return (22/7) * radius * radius;
    }
    float perimeter()
    {
        return 2 * (22/7) * radius;
    }
    void display()
    {
        cout << "Area = " << area() << endl;
        cout << "Perimeter = " << perimeter() << endl;
    }
};
class Triangle:public Shape{
    private:
    float side1,side2,side3; 

public:
    Triangle(float x, float y,float z)
    {
        side1 = x;
        side2 = y;
        side3 = z;
    }

    float area()
    {
        float s=0;
        s=(side1+side2+side3)/2;
        return sqrt(s*(s-side1)*(s-side2)*(s-side3));
    }

    float perimeter()
    {
        return side1+side2+side3;
    }
    void display()
    {
        cout << "Area = " << area() << endl;
        cout << "Perimeter = " << perimeter() << endl;
    }
};
int main()
{
    Shape *ptr;
    Rectangle rect(5, 4);
    Circle cir(7);
    Triangle tri(3,4,5);
    cout << "Rectangle:" << endl;
    ptr = &rect;
    ptr->display();
    cout << "Circle:" << endl;
    ptr = &cir;
    ptr->display();
    cout<<"Triangle"<<endl;
    ptr = &tri;
    ptr->display();
    return 0;
}
