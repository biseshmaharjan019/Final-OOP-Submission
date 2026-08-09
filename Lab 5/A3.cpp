#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    float x, y, z;

public:    Vector3D(float x_val = 0.0f, float y_val = 0.0f, float z_val = 0.0f) 
        : x(x_val), y(y_val), z(z_val) {}

    // Converting constructor initializing all 3 components to given value
    Vector3D(float val) : x(val), y(val), z(val) {}
    Vector3D operator+(const Vector3D& v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }
    Vector3D operator-(const Vector3D& v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }
    Vector3D operator-() const {
        return Vector3D(-x, -y, -z);
    }
    friend float operator*(const Vector3D& v1, const Vector3D& v2) {
        return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
    }
    friend Vector3D operator*(const Vector3D& v, float scalar) {
        return Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
    }

    friend Vector3D operator*(float scalar, const Vector3D& v) {
        return Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
    }
    operator float() const {
        return sqrt(x * x + y * y + z * z);
    }
    friend ostream& operator<<(ostream& os, const Vector3D& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }

    friend istream& operator>>(istream& is, Vector3D& v) {
        cout << "Enter x, y, z components: ";
        is >> v.x >> v.y >> v.z;
        return is;
    }
};

int main() {
    Vector3D v1(3.0f, 4.0f, 0.0f);
    Vector3D v2(1.0f, 2.0f, 2.0f);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "-v1 = " << (-v1) << endl;
    float dot = v1 * v2;
    cout << "Dot Product (v1 * v2) = " << dot << endl;
    Vector3D vScaled = v1 * 2.5f;
    cout << "Scalar Multiply (v1 * 2.5) = " << vScaled << endl;
    float mag = float(v1);
    cout << "Magnitude of v1 (operator float) = " << mag << endl;
    Vector3D vUniform = 5.0f;
    cout << "Uniform Vector initialized with 5.0f: " << vUniform << endl;

    return 0;
}