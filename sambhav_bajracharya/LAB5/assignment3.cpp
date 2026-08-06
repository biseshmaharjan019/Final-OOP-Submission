#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    float x;
    float y;
    float z;

public:
    Vector3D(float val = 0.0f) {
        x = val;
        y = val;
        z = val;
    }

    Vector3D(float xVal, float yVal, float zVal) {
        x = xVal;
        y = yVal;
        z = zVal;
    }

    Vector3D operator+(const Vector3D& v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(const Vector3D& v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    Vector3D operator-() const {
        return Vector3D(-x, -y, -z);
    }

    operator float() const {
        return sqrt(x * x + y * y + z * z);
    }

    friend float operator*(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator*(const Vector3D& v, float scalar);
    friend Vector3D operator*(float scalar, const Vector3D& v);

    friend ostream& operator<<(ostream& out, const Vector3D& v);
    friend istream& operator>>(istream& in, Vector3D& v);
};

float operator*(const Vector3D& v1, const Vector3D& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector3D operator*(const Vector3D& v, float scalar) {
    return Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
}

Vector3D operator*(float scalar, const Vector3D& v) {
    return v * scalar;
}

ostream& operator<<(ostream& out, const Vector3D& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

istream& operator>>(istream& in, Vector3D& v) {
    cout << "Enter x, y, and z components: ";
    in >> v.x >> v.y >> v.z;
    return in;
}

int main() {
    Vector3D v1(3.0f, 4.0f, 0.0f);
    Vector3D v2(1.0f, 2.0f, 2.0f);

    cout << "Vector v1: " << v1 << endl;
    cout << "Vector v2: " << v2 << endl;

    cout << "Sum (v1 + v2): " << (v1 + v2) << endl;
    cout << "Difference (v1 - v2): " << (v1 - v2) << endl;
    cout << "Negation (-v1): " << (-v1) << endl;

    float dotProduct = v1 * v2;
    cout << "Dot product (v1 * v2): " << dotProduct << endl;

    cout << "v1 * 2.5: " << (v1 * 2.5f) << endl;
    cout << "2.5 * v1: " << (2.5f * v1) << endl;

    float magnitude = (float)v1;
    cout << "Magnitude of v1: " << magnitude << endl;

    Vector3D singleVal(5.0f);
    cout << "Vector initialized with single float 5.0: " << singleVal << endl;

    return 0;
}
