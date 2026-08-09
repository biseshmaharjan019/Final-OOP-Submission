#include<iostream>
#include<cmath>
using namespace std;
class Shape{
public:
virtual float area() =0;
virtual float perimeter() =0;

virtual void display(){

cout<<"Area = "<<area()<<endl;
cout<<"perimeter = "<<perimeter()<<endl;
}
};
class Circle: public Shape{
float r;

public:
Circle(float radius){
r= radius; }
float area() {
return 3.14*r*r;
}
float perimeter() {
return 2*3.14*r;
}
};
class Rectangle: public Shape{
float l,b;

public:
Rectangle(float length, float breadth){
l = length;
b = breadth;
 }
float area() {
return l * b;
}
float perimeter() {
return 2*(l + b);
}
};
class Triangle: public Shape{
float a,b,c;

public:
Triangle(float x, float y,float z){
a= x;
b=y;
c=z; }

float perimeter() {
return a+b+c;
}
float area() {
float s= perimeter()/2;
return sqrt(s * (s - a) * (s - b) * (s - c));
}
};
int main()
{
Shape *p;

Circle c(4);
    Rectangle r(10, 5);
    Triangle t(1, 2, 3);

    p= &c;
    cout << "Circle" << endl;
    p->display();

    cout << endl;

    p = &r;
    cout << "Rectangle" << endl;
    p->display();

    cout << endl;

    p = &t;
    cout << "Triangle" << endl;
    p->display();


    return 0;
}
