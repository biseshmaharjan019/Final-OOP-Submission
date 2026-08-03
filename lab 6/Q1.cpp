#include<iostream>
using namespace std;

class Complex {
    float real, imag;
public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }


    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    friend bool operator==(Complex c1, Complex c2);

  
    friend ostream& operator<<(ostream& out, Complex c);
    friend istream& operator>>(istream& in, Complex& c);
};

bool operator==(Complex c1, Complex c2) {
    return (c1.real == c2.real && c1.imag == c2.imag);
}

ostream& operator<<(ostream& out, Complex c) {
    if(c.imag < 0)
        out << "(" << c.real << " - " << -c.imag << "i)";
    else
        out << "(" << c.real << " + " << c.imag << "i)";
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
    cin >> c1;
    cin >> c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;

    if(c1 == c2)
        cout << "c1 and c2 are equal." << endl;
    else
        cout << "c1 and c2 are not equal." << endl;

    return 0;
}