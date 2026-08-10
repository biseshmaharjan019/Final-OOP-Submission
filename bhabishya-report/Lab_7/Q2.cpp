#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    // Shape s; // Not allowed because Shape is abstract.
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
    virtual void display() const { cout << "Area: " << area() << endl << "Perimeter: " << perimeter() << endl; }
    virtual ~Shape() {}
};
class Circle: public Shape { float r; public: Circle(float x):r(x){} float area()const override{return 3.14159f*r*r;} float perimeter()const override{return 2*3.14159f*r;} };
class Rectangle: public Shape { float l,w; public: Rectangle(float a,float b):l(a),w(b){} float area()const override{return l*w;} float perimeter()const override{return 2*(l+w);} };
class Triangle: public Shape { float a,b,c; public: Triangle(float x,float y,float z):a(x),b(y),c(z){} float area()const override{float s=(a+b+c)/2;return sqrt(s*(s-a)*(s-b)*(s-c));} float perimeter()const override{return a+b+c;} };
int main(){Circle c(5);Rectangle r(10,6);Triangle t(3,4,5);Shape* p;
cout<<"Circle:"<<endl;p=&c;p->display();cout<<"\nRectangle:"<<endl;p=&r;p->display();cout<<"\nTriangle:"<<endl;p=&t;p->display();system("pause");return 0;}
