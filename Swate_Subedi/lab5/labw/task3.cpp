#include <iostream>
using namespace std;

class F;

class C {
private:
    float t;

public:
    C(float temp = 0) : t(temp) {}

    operator float() const { return t; }

    operator F() const;

    float getT() const { return t; }

    friend ostream& operator<<(ostream& out, const C& c);
};

class F {
private:
    float t;

public:
    F(float temp = 0) : t(temp) {}

    F(const C& c) {
        t = c.getT() * 9.0f / 5.0f + 32;
    }

    float getT() const { return t; }

    friend ostream& operator<<(ostream& out, const F& f);
};

C::operator F() const {
    return F(t * 9.0f / 5.0f + 32);
}

ostream& operator<<(ostream& out, const C& c) {
    out << c.t << "C";
    return out;
}

ostream& operator<<(ostream& out, const F& f) {
    out << f.t << "F";
    return out;
}

int main() {
    C c1 = 25.0f;
    cout << "Celsius: " << c1 << endl;

    float v = static_cast<float>(c1);
    cout << "Float: " << v << endl;

    F f1 = c1.operator F();
    cout << "Conv Op: " << f1 << endl;

    F f2(c1);
    cout << "Conv Ctor: " << f2 << endl;

    return 0;
}
