#include <iostream>
#include <cmath>
using namespace std;

class S {
public:
    virtual float a() const = 0;
    virtual float p() const = 0;
    virtual void show() const {
        cout << "Area: " << a() << "\nPerimeter: " << p() << endl;
    }
};

class C : public S {
private:
    float r;
public:
    C(float rad) : r(rad) {}
    float a() const override { return 3.1416 * r * r; }
    float p() const override { return 2 * 3.1416 * r; }
};

class R : public S {
private:
    float l, b;
public:
    R(float len, float br) : l(len), b(br) {}
    float a() const override { return l * b; }
    float p() const override { return 2 * (l + b); }
};

class T : public S {
private:
    float x, y, z;
public:
    T(float a, float b, float c) : x(a), y(b), z(c) {}
    float a() const override {
        float s = (x + y + z) / 2;
        return sqrt(s * (s - x) * (s - y) * (s - z));
    }
    float p() const override { return x + y + z; }
};

int main() {
    C cir(5);
    R rect(4, 6);
    T tri(3, 4, 5);
    S* p;

    cout << "Circle:\n"; p = &cir; p->show();
    cout << "\nRectangle:\n"; p = &rect; p->show();
    cout << "\nTriangle:\n"; p = &tri; p->show();

    return 0;
}
