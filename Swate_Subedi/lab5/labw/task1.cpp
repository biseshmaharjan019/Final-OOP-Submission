#include <iostream>
using namespace std;

class C {
private:
    float r, i;

public:
    C(float a = 0, float b = 0) : r(a), i(b) {}

    C operator+(const C& o) const { return C(r + o.r, i + o.i); }
    C operator-(const C& o) const { return C(r - o.r, i - o.i); }

    friend bool operator==(const C& a, const C& b);
    friend istream& operator>>(istream& in, C& c);
    friend ostream& operator<<(ostream& out, const C& c);
};

bool operator==(const C& a, const C& b) {
    return a.r == b.r && a.i == b.i;
}

istream& operator>>(istream& in, C& c) {
    in >> c.r >> c.i;
    return in;
}

ostream& operator<<(ostream& out, const C& c) {
    out << "(" << c.r;
    out << (c.i >= 0 ? " + " : " - ") << (c.i >= 0 ? c.i : -c.i) << "i)";
    return out;
}

int main() {
    C a, b;

    cout << "Enter real and imaginary parts of first complex: ";
    cin >> a;

    cout << "Enter real and imaginary parts of second complex: ";
    cin >> b;

    C s = a + b, d = a - b;

    cout << "\nFirst: " << a << "\nSecond: " << b
         << "\nSum: " << s << "\nDiff: " << d << "\n";

    cout << (a == b ? "Equal" : "Not equal") << endl;

    return 0;
}
