#include <iostream>
#include <numeric>
#include <cmath>
#include <stdexcept>
using namespace std;

class F {
private:
    int n, d;

    void rdc() {
        if (d == 0) throw invalid_argument("Zero denom");
        if (d < 0) { n = -n; d = -d; }
        int g = gcd(abs(n), abs(d));
        n /= g; d /= g;
    }

public:
    F(int num = 0, int den = 1) : n(num), d(den) { rdc(); }

    F(double v) {
        double e = 1e9;
        int bn = 0, bd = 1;
        for (int i = 1; i <= 1000; i++) {
            int x = static_cast<int>(round(v * i));
            double err = abs(v - static_cast<double>(x) / i);
            if (err < e) { e = err; bn = x; bd = i; }
        }
        n = bn; d = bd; rdc();
    }

    operator double() const { return static_cast<double>(n) / d; }

    friend F operator+(const F& a, const F& b);
    friend F operator-(const F& a, const F& b);
    friend F operator*(const F& a, const F& b);
    friend F operator/(const F& a, const F& b);
    friend bool operator<(const F& a, const F& b);
    friend bool operator>(const F& a, const F& b);
    friend bool operator==(const F& a, const F& b);
    friend istream& operator>>(istream& in, F& f);
    friend ostream& operator<<(ostream& out, const F& f);
};

F operator+(const F& a, const F& b) {
    return F(a.n * b.d + b.n * a.d, a.d * b.d);
}

F operator-(const F& a, const F& b) {
    return F(a.n * b.d - b.n * a.d, a.d * b.d);
}

F operator*(const F& a, const F& b) {
    return F(a.n * b.n, a.d * b.d);
}

F operator/(const F& a, const F& b) {
    if (b.n == 0) throw invalid_argument("Div by zero");
    return F(a.n * b.d, a.d * b.n);
}

bool operator<(const F& a, const F& b) {
    return a.n * b.d < b.n * a.d;
}

bool operator>(const F& a, const F& b) {
    return a.n * b.d > b.n * a.d;
}

bool operator==(const F& a, const F& b) {
    return a.n == b.n && a.d == b.d;
}

istream& operator>>(istream& in, F& f) {
    int x, y; char c;
    in >> x >> c >> y;
    if (c != '/' || y == 0) { in.setstate(ios::failbit); return in; }
    f = F(x, y);
    return in;
}

ostream& operator<<(ostream& out, const F& f) {
    out << f.n << "/" << f.d;
    return out;
}

int main() {
    try {
        F a, b;
        cout << "Enter a/b: "; cin >> a;
        cout << "Enter c/d: "; cin >> b;
        if (!cin) { cout << "Invalid\n"; return 1; }

        cout << "\nA: " << a << "\nB: " << b;
        cout << "\nA+B: " << a + b;
        cout << "\nA-B: " << a - b;
        cout << "\nA*B: " << a * b;
        cout << "\nA/B: " << a / b;
        cout << "\nA as double: " << static_cast<double>(a);

        cout << "\n" << (a < b ? "A < B" : a > b ? "A > B" : "A == B");

        double x;
        cout << "\n\nEnter decimal: ";
        cin >> x;
        cout << "Approx: " << F(x) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
