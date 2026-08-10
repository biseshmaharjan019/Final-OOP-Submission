#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0.0f, float i = 0.0f) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    friend bool operator==(const Complex& c1, const Complex& c2);
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};

bool operator==(const Complex& c1, const Complex& c2) {
    return (c1.real == c2.real) && (c1.imag == c2.imag);
}

ostream& operator<<(ostream& out, const Complex& c) {
    if (c.imag >= 0) {
        out << "(" << c.real << " + " << c.imag << "i)";
    } else {
        out << "(" << c.real << " - " << -c.imag << "i)";
    }
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nFirst Number: " << c1 << endl;
    cout << "Second Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    if (c1 == c2) {
        cout << "Both complex numbers are equal." << endl;
    } else {
        cout << "The complex numbers are not equal." << endl;
    }

    return 0;
}
