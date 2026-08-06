#include<iostream>
#include<cmath>
using namespace std;
class Shape{
public:
    virtual float area()=0;
    virtual float perimeter()=0;
    void display(){
        cout << "Area = " <<area() <<endl;
        cout << "Perimeter = " <<perimeter() <<endl;
    }
};
class Circle: public Shape{
private:
    float radius;
public:
    Circle(float r){
        radius = r;
    }
    float area(){
        return 3.14*radius*radius;
    }
    float perimeter(){
        return 2*3.14*radius;
    }
};
class Rectangle: public Shape{
private:
    float length, breadth;
public:
    Rectangle(float l,float b){
        length=l;
        breadth=b;
    }
    float area(){
        return length*breadth;
    }
    float perimeter(){
        return 2*(length+breadth);
    }
};
class Triangle: public Shape{
private:
    float a,b,c;
public:
    Triangle(float x,float y,float z){
        a=x;
        b=y;
        c=z;
    }
    float perimeter(){
        return a+b+c;
    }
    float area(){
        float s = perimeter()/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};
int main()
{
    Shape *ptr;
    Circle c(3);
    Rectangle r(3,13);
    Triangle t(3,4,5);
    ptr=&c;
    cout << "Circle: " <<endl;
    ptr->display();
    cout << endl;
    ptr=&r;
    cout << "Rectangle: " <<endl;
    ptr->display();
    cout << endl;
    ptr=&t;
    cout << "Triangle: " <<endl;
    ptr->display();
    cout << endl;
    return 0;
}
