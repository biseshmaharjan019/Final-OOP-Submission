#include<iostream>
using namespace std;
class Shape {
private:
    string color;
public:
    Shape(string c) {
        color = c;
    }
    string getColor() {
        return color;
    }
    virtual float area() = 0; 
};
class Circle : public Shape {
private:
    float radius;
public:
    Circle(string c, float r) : Shape(c) {
        radius = r;
    }
    float area() {
        return 3.14 * radius * radius;
    }
    void display() {
        cout << "Circle" << endl;
        cout << "Color : " << getColor() << endl;
        cout << "Area  : " << area() << endl;
    }
};
class Rectangle : public Shape {
private:
    float length, breadth;
public:
    Rectangle(string c, float l, float b) : Shape(c) {
        length = l;
        breadth = b;
    }
    float area() {
        return length * breadth;
    }
    void display() {
        cout << "Rectangle" << endl;
        cout << "Color : " << getColor() << endl;
        cout << "Area  : " << area() << endl;
    }
};
class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(string c, float b, float h) : Shape(c) {
        base = b;
        height = h;
    }
    float area() {
        return 0.5 * base * height;
    }
    void display() {
        cout << "Triangle" << endl;
        cout << "Color : " << getColor() << endl;
        cout << "Area  : " << area() << endl;
    }
};
int main() {
    Circle c("Purple", 7);
    Rectangle r("Brown", 10, 5);
    Triangle t("Blue", 8, 6);
    c.display();
    cout << endl;
    r.display();
    cout << endl;
    t.display();
    return 0;
}
