#include <iostream>
#include <cmath>
using namespace std;
class Shape
{
public:
    virtual float area()=0;
    virtual float perimeter()=0;
    virtual void display()
    {
        cout<<"Area = "<<area()<<endl;
        cout<<"Perimeter = "<<perimeter()<<endl;
    }
    virtual ~Shape(){}
};
class Circle : public Shape
{
    float radius;
public:
    Circle(float r):radius(r){}
    float area() override
    {
        return 3.14159f*radius*radius;
    }
    float perimeter() override
    {
        return 2*3.14159f*radius;
    }
};
class Rectangle : public Shape
{
    float length,width;
public:
    Rectangle(float l,float w):length(l),width(w){}
    float area() override
    {
        return length*width;
    }

    float perimeter() override
    {
        return 2*(length+width);
    }
};
class Triangle : public Shape
{
    float a,b,c;
public:
    Triangle(float x,float y,float z):a(x),b(y),c(z){}

    float perimeter() override
    {
        return a+b+c;
    }
    float area() override
    {
        float s=perimeter()/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};
int main()
{
    Shape* ptr;
    Circle c(5);
    Rectangle r(10,4);
    Triangle t(3,4,5);
    ptr=&c;
    ptr->display();
    ptr=&r;
    ptr->display();
    ptr=&t;
    ptr->display();
    return 0;
}
