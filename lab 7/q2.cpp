#include<iostream>
using namespace std;

class Shape{
public:
    virtual float area()=0;
    virtual float perimeter()=0;

    virtual void display()
    {
        cout<<"Area = "<<area()<<endl;
        cout<<"Perimeter = "<<perimeter()<<endl;
    }
};

class Circle:public Shape{
    float r;
public:
    Circle(float x){ r=x; }

    float area(){ return 3.14*r*r; }

    float perimeter(){ return 2*3.14*r; }
};

class Rectangle:public Shape{
    float l,b;
public:
    Rectangle(float x,float y)
    {
        l=x;
        b=y;
    }

    float area(){ return l*b; }

    float perimeter(){ return 2*(l+b); }
};

class Triangle:public Shape{
    float a,b,c;
public:
    Triangle(float x,float y,float z)
    {
        a=x;b=y;c=z;
    }

    float area(){ return 6; }      // Simple value

    float perimeter(){ return a+b+c; }
};

int main()
{
    Shape *s;

    Circle c(5);
    Rectangle r(4,3);
    Triangle t(3,4,5);

    s=&c;
    s->display();

    s=&r;
    s->display();

    s=&t;
    s->display();

    // Shape obj;  // Error: Abstract class

    return 0;
}