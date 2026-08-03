#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default and parameterized constructor
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // Binary + operator as member function
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Binary - operator as member function
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // Friend functions declarations
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};

// Friend function for equality check
bool operator==(const Complex& c1, const Complex& c2) {
    return (c1.real == c2.real && c1.imag == c2.imag);
}

// Friend function for output formatting (a + bi)
ostream& operator<<(ostream& out, const Complex& c) {
    if (c.imag >= 0)
        out << "(" << c.real << " + " << c.imag << "i)";
    else
        out << "(" << c.real << " - " << -c.imag << "i)";
    return out;
}

// Friend function for input format
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

    cout << "\nResults:\n";
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum (c1 + c2) = " << sum << endl;
    cout << "Difference (c1 - c2) = " << diff << endl;

    if (c1 == c2) {
        cout << "c1 and c2 are equal." << endl;
    } else {
        cout << "c1 and c2 are not equal." << endl;
    }

    return 0;
}
