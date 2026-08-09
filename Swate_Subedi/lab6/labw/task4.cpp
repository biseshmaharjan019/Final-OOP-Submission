#include <iostream>
using namespace std;

class S {
private:
    string c;

public:
    S(string col) : c(col) {}
    string getC() const { return c; }
    virtual float a() = 0;
};

class C : public S {
private:
    float r;

public:
    C(string col, float rad) : S(col), r(rad) {}
    float a() { return 3.1416 * r * r; }
    void show() {
        cout << "Circle Color: " << getC() << "\nArea: " << a() << endl;
    }
};

class R : public S {
private:
    float l, b;

public:
    R(string col, float len, float br) : S(col), l(len), b(br) {}
    float a() { return l * b; }
    void show() {
        cout << "Rectangle Color: " << getC() << "\nArea: " << a() << endl;
    }
};

class T : public S {
private:
    float b, h;

public:
    T(string col, float base, float height) : S(col), b(base), h(height) {}
    float a() { return 0.5 * b * h; }
    void show() {
        cout << "Triangle Color: " << getC() << "\nArea: " << a() << endl;
    }
};

int main() {
    C c("Red", 5);
    R r("Blue", 4, 6);
    T t("Green", 5, 8);

    c.show(); cout << endl;
    r.show(); cout << endl;
    t.show();

    return 0;
}
