#include <iostream>
#include <cmath>
using namespace std;

class V {
private:
    float x, y, z;

public:
    V(float v = 0) : x(v), y(v), z(v) {}
    V(float a, float b, float c) : x(a), y(b), z(c) {}

    V operator+(const V& v) const { return V(x + v.x, y + v.y, z + v.z); }
    V operator-(const V& v) const { return V(x - v.x, y - v.y, z - v.z); }
    V operator-() const { return V(-x, -y, -z); }

    operator float() const { return sqrt(x*x + y*y + z*z); }

    friend float operator*(const V& a, const V& b);
    friend V operator*(const V& v, float s);
    friend V operator*(float s, const V& v);
    friend istream& operator>>(istream& in, V& v);
    friend ostream& operator<<(ostream& out, const V& v);
};

float operator*(const V& a, const V& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

V operator*(const V& v, float s) {
    return V(v.x * s, v.y * s, v.z * s);
}

V operator*(float s, const V& v) { return v * s; }

istream& operator>>(istream& in, V& v) {
    in >> v.x >> v.y >> v.z;
    return in;
}

ostream& operator<<(ostream& out, const V& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

int main() {
    V a, b;
    cout << "Enter x y z for V1: "; cin >> a;
    cout << "Enter x y z for V2: "; cin >> b;

    cout << "\nV1: " << a << "\nV2: " << b;
    cout << "\nSum: " << a + b;
    cout << "\nDiff: " << a - b;
    cout << "\nNeg V1: " << -a;
    cout << "\nDot: " << a * b;
    cout << "\nV1 * 2: " << a * 2.0f;
    cout << "\n3 * V2: " << 3.0f * b;
    cout << "\nMag V1: " << static_cast<float>(a);
    cout << "\nV from 5: " << V(5.0f) << endl;

    return 0;
}
