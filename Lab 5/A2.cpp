#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    static int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a == 0) ? 1 : a;
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

public:    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) denominator = 1;
        reduce();
    }
    Fraction(double val) {
        int best_num = 0, best_den = 1;
        double min_err = 1e9;

        for (int d = 1; d <= 1000; ++d) {
            int n = (int)round(val * d);
            double err = fabs(val - (double)n / d);
            if (err < min_err) {
                min_err = err;
                best_num = n;
                best_den = d;
            }
        }
        numerator = best_num;
        denominator = best_den;
        reduce();
    }
    operator double() const {
        return (double)numerator / denominator;
    }
    friend Fraction operator+(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                        f1.denominator * f2.denominator);
    }

    friend Fraction operator-(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                        f1.denominator * f2.denominator);
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
    }

    friend Fraction operator/(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
    }
    friend bool operator==(const Fraction& f1, const Fraction& f2) {
        return (f1.numerator == f2.numerator && f1.denominator == f2.denominator);
    }

    friend bool operator<(const Fraction& f1, const Fraction& f2) {
        return (double)f1 < (double)f2;
    }

    friend bool operator>(const Fraction& f1, const Fraction& f2) {
        return (double)f1 > (double)f2;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) f.denominator = 1;
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4); // Reduces to 1/2
    Fraction f2(3, 4);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    cout << "\nRelational Tests:" << endl;
    cout << "f1 < f2: " << (f1 < f2 ? "True" : "False") << endl;
    cout << "f1 > f2: " << (f1 > f2 ? "True" : "False") << endl;
    cout << "f1 == f2: " << (f1 == f2 ? "True" : "False") << endl;
    double dec = (double)f2;
    cout << "\nFraction f2 as double: " << dec << endl;
    Fraction approx(0.333333);
    cout << "Double 0.333333 approximated as Fraction: " << approx << endl;

    return 0;