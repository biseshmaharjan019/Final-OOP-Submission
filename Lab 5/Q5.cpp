// Fraction Class with Operator Overloading and Type Conversion

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Fraction
{
    int numerator, denominator;

    void reduce()
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        int a = abs(numerator);
        int b = abs(denominator);
        while (b)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        if (a)
        {
            numerator /= a;
            denominator /= a;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d == 0 ? 1 : d)
    {
        reduce();
    }

    Fraction(double value)
    {
        int sign = value < 0 ? -1 : 1;
        value = fabs(value);
        int bestN = 0;
        int bestD = 1;
        double error = value;

        for (int d = 1; d <= 1000; d++)
        {
            int n = (int)round(value * d);
            double e = fabs(value - (double)n / d);
            if (e < error)
            {
                error = e;
                bestN = n;
                bestD = d;
            }
        }
        numerator = sign * bestN;
        denominator = bestD;
        reduce();
    }

    friend Fraction operator+(const Fraction &, const Fraction &);
    friend Fraction operator-(const Fraction &, const Fraction &);
    friend Fraction operator*(const Fraction &, const Fraction &);
    friend Fraction operator/(const Fraction &, const Fraction &);
    friend bool operator<(const Fraction &, const Fraction &);
    friend bool operator>(const Fraction &, const Fraction &);
    friend bool operator==(const Fraction &, const Fraction &);
    friend ostream &operator<<(ostream &, const Fraction &);
    friend istream &operator>>(istream &, Fraction &);

    operator double() const
    {
        return (double)numerator / denominator;
    }
};

Fraction operator+(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}

Fraction operator-(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
}

Fraction operator*(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}

Fraction operator/(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
}

bool operator<(const Fraction &a, const Fraction &b)
{
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

bool operator>(const Fraction &a, const Fraction &b)
{
    return a.numerator * b.denominator > b.numerator * a.denominator;
}

bool operator==(const Fraction &a, const Fraction &b)
{
    return a.numerator * b.denominator == b.numerator * a.denominator;
}

ostream &operator<<(ostream &out, const Fraction &f)
{
    return out << f.numerator << "/" << f.denominator;
}

istream &operator>>(istream &in, Fraction &f)
{
    char slash;
    in >> f.numerator >> slash >> f.denominator;
    f.reduce();
    return in;
}

int main()
{
    Fraction a, b;

    cout << "Enter first fraction (num/den): ";
    cin >> a;

    cout << "Enter second fraction (num/den): ";
    cin >> b;

    cout << "\nA = " << a << "\nB = " << b << "\nA+B = " << a + b << "\nA-B = " << a - b << "\nA*B = " << a * b << "\nA/B = " << a / b << endl;
    cout << "A < B: " << (a < b ? "true" : "false") << "\nA > B: " << (a > b ? "true" : "false") << "\nA == B: " << (a == b ? "true" : "false") << endl;

    double value = a;
    cout << "A as decimal: " << value << endl;

    Fraction f(3.14159);
    cout << "3.14159 as fraction: " << f << endl;

    system("pause");
    return 0;
}