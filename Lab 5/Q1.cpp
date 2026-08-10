// Complex Number Class with Operator Overloading

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Complex
{
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    friend bool operator==(const Complex &a, const Complex &b);
    friend ostream &operator<<(ostream &out, const Complex &c);
    friend istream &operator>>(istream &in, Complex &c);
};

bool operator==(const Complex &a, const Complex &b)
{
    return a.real == b.real && a.imag == b.imag;
}

ostream &operator<<(ostream &out, const Complex &c)
{
    return out << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i)";
}

istream &operator>>(istream &in, Complex &c)
{
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main()
{
    Complex a, b;

    cout << "Complex 1:\n";
    cin >> a;

    cout << "Complex 2:\n";
    cin >> b;

    cout << "\nA = " << a << "\nB = " << b << "\nA+B = " << a + b << "\nA-B = " << a - b << endl;
    cout << (a == b ? "A and B are equal." : "A and B are not equal.") << endl;

    system("pause");
    return 0;
}