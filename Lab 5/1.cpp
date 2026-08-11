#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0.0f, float i = 0.0f) : real(r), imag(i) {}
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }
    friend bool operator==(const Complex& c1, const Complex& c2) {
        return (c1.real == c2.real && c1.imag == c2.imag);
    }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << "(" << c.real;
        if (c.imag >= 0)
            os << " + " << c.imag << "i)";
        else
            os << " - " << -c.imag << "i)";
        return os;
    }
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2;
    cout << "Enter First Complex Number" << endl;
    cin >> c1;
    cout << "Enter Second Complex Number" << endl;
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nc1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;

    if (c1 == c2) {
        cout << "c1 and c2 are equal." << endl;
    } else {
        cout << "c1 and c2 are not equal." << endl;
    }

    return 0;
}