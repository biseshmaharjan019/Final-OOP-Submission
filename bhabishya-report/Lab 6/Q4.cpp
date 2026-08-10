#include <iostream>
#include <string>
using namespace std;
class Shape{string color;public:Shape(string c):color(c){}string getColor()const{return color;}virtual float area()const=0;virtual~Shape(){}};
class Circle:public Shape{float radius;public:Circle(string c,float r):Shape(c),radius(r){}float area()const override{return 3.14159f*radius*radius;}void display()const{cout<<"Circle\nColor: "<<getColor()<<"\nArea: "<<area()<<endl;}};
class Rectangle:public Shape{float length,width;public:Rectangle(string c,float l,float w):Shape(c),length(l),width(w){}float area()const override{return length*width;}void display()const{cout<<"Rectangle\nColor: "<<getColor()<<"\nArea: "<<area()<<endl;}};
class Triangle:public Shape{float base,height;public:Triangle(string c,float b,float h):Shape(c),base(b),height(h){}float area()const override{return .5f*base*height;}void display()const{cout<<"Triangle\nColor: "<<getColor()<<"\nArea: "<<area()<<endl;}};
int main(){Circle c("Red",5);Rectangle r("Blue",10,6);Triangle t("Green",8,4);c.display();cout<<endl;r.display();cout<<endl;t.display();system("pause");return 0;}