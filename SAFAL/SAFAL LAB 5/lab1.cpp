#include <iostream>
using namespace std;
class Complex {
private:
    float real, imag;
public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

bool operator==(const Complex& c1, const Complex& c2) {
    return (c1.real == c2.real && c1.imag == c2.imag);
}
istream& operator>>(istream& in, Complex& c) {
    in >> c.real >> c.imag;
    return in;
}
ostream& operator<<(ostream& out, const Complex& c) {
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}
int main() {
    Complex c1, c2;
    cout << "Enter first complex (real imag): ";
    cin >> c1;
    cout << "Enter second complex (real imag): ";
    cin >> c2;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    if (c1 == c2)
        cout << "Complex numbers are equal\n";
    else
        cout << "Complex numbers are not equal\n";

    return 0;
}
