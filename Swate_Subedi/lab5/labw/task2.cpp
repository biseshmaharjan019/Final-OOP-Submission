#include <iostream>
using namespace std;

class D {
private:
    int f;
    float i;

    void norm() {
        float t = f * 12 + i;
        f = static_cast<int>(t / 12);
        i = t - f * 12;
    }

public:
    D(int ft = 0, float in = 0) : f(ft), i(in) { norm(); }

    D operator-() const { return D(-f, -i); }

    D& operator++() {
        i++;
        norm();
        return *this;
    }

    D operator++(int) {
        D old = *this;
        i++;
        norm();
        return old;
    }

    friend D operator*(const D& d, int s);
    friend D operator*(int s, const D& d);

    void show() const {
        cout << f << "ft " << i << "in";
    }
};

D operator*(const D& d, int s) {
    float t = (d.f * 12 + d.i) * s;
    return D(0, t);
}

D operator*(int s, const D& d) {
    return d * s;
}

int main() {
    D d1(5, 11);

    cout << "Original: ";
    d1.show();

    D neg = -d1;
    cout << "\nNegated: ";
    neg.show();

    cout << "\n\nPrefix ++: ";
    (++d1).show();

    cout << "\nPostfix return: ";
    (d1++).show();

    cout << "\nAfter postfix: ";
    d1.show();

    D d2 = d1 * 2;
    cout << "\n\nd1 * 2: ";
    d2.show();

    D d3 = 3 * d1;
    cout << "\n3 * d1: ";
    d3.show();

    cout << endl;
    return 0;
}
