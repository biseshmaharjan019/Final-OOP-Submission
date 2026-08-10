#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a == 0 ? 1 : a;
    }

    void reduce() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    Fraction(int num = 0, int den = 1) {
        numerator = num;
        denominator = (den == 0) ? 1 : den;
        reduce();
    }

    Fraction(double val) {
        int bestNum = 0;
        int bestDen = 1;
        double minDiff = 1e9;

        for (int den = 1; den <= 1000; den++) {
            int num = round(val * den);
            double diff = abs(val - (double)num / den);
            if (diff < minDiff) {
                minDiff = diff;
                bestNum = num;
                bestDen = den;
            }
        }
        numerator = bestNum;
        denominator = bestDen;
        reduce();
    }

    operator double() const {
        return (double)numerator / denominator;
    }

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);

    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator==(const Fraction& f1, const Fraction& f2);

    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.numerator * f2.denominator + f2.numerator * f1.denominator, 
                    f1.denominator * f2.denominator);
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.numerator * f2.denominator - f2.numerator * f1.denominator, 
                    f1.denominator * f2.denominator);
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
}

bool operator<(const Fraction& f1, const Fraction& f2) {
    return (double)f1 < (double)f2;
}

bool operator>(const Fraction& f1, const Fraction& f2) {
    return (double)f1 > (double)f2;
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator == f2.numerator) && (f1.denominator == f2.denominator);
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

istream& operator>>(istream& in, Fraction& f) {
    char slash;
    in >> f.numerator >> slash >> f.denominator;
    if (f.denominator == 0) {
        f.denominator = 1;
    }
    f.reduce();
    return in;
}

int main() {
    Fraction f1(3, 4);
    Fraction f2(2, 5);

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;

    cout << "Addition: " << (f1 + f2) << endl;
    cout << "Subtraction: " << (f1 - f2) << endl;
    cout << "Multiplication: " << (f1 * f2) << endl;
    cout << "Division: " << (f1 / f2) << endl;

    if (f1 > f2) {
        cout << f1 << " is greater than " << f2 << endl;
    } else if (f1 < f2) {
        cout << f1 << " is less than " << f2 << endl;
    }

    if (f1 == f2) {
        cout << "Fractions are equal." << endl;
    }

    double dVal = (double)f1;
    cout << "Decimal value of " << f1 << " is " << dVal << endl;

    Fraction approx(0.75);
    cout << "Double 0.75 converted to fraction: " << approx << endl;

    return 0;
}
