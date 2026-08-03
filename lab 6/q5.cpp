#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
private:
    int numerator, denominator;

    void reduce()
    {
        int a = abs(numerator);
        int b = abs(denominator);

        while(b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }

        numerator /= a;
        denominator /= a;

        if(denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    Fraction(int n=0,int d=1)
    {
        numerator=n;
        denominator=d;
        reduce();
    }

    Fraction(double value)
    {
        denominator=1000;
        numerator=(int)(value*1000);
        reduce();
    }

    operator double() const
    {
        return (double)numerator/denominator;
    }

    friend Fraction operator+(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.denominator+b.numerator*a.denominator,
                        a.denominator*b.denominator);
    }

    friend Fraction operator-(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.denominator-b.numerator*a.denominator,
                        a.denominator*b.denominator);
    }

    friend Fraction operator*(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.numerator,
                        a.denominator*b.denominator);
    }

    friend Fraction operator/(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.denominator,
                        a.denominator*b.numerator);
    }

    friend bool operator<(Fraction a,Fraction b)
    {
        return a.numerator*b.denominator < b.numerator*a.denominator;
    }

    friend bool operator>(Fraction a,Fraction b)
    {
        return a.numerator*b.denominator > b.numerator*a.denominator;
    }

    friend bool operator==(Fraction a,Fraction b)
    {
        return a.numerator==b.numerator &&
               a.denominator==b.denominator;
    }

    friend ostream& operator<<(ostream &out,const Fraction &f)
    {
        out<<f.numerator<<"/"<<f.denominator;
        return out;
    }

    friend istream& operator>>(istream &in,Fraction &f)
    {
        char slash;
        in>>f.numerator>>slash>>f.denominator;
        f.reduce();
        return in;
    }
};

int main()
{
    Fraction f1,f2;

    cout<<"Enter first fraction (a/b): ";
    cin>>f1;

    cout<<"Enter second fraction (a/b): ";
    cin>>f2;

    cout<<"Addition = "<<f1+f2<<endl;
    cout<<"Subtraction = "<<f1-f2<<endl;
    cout<<"Multiplication = "<<f1*f2<<endl;
    cout<<"Division = "<<f1/f2<<endl;

    cout<<"f1 < f2 = "<<(f1<f2)<<endl;
    cout<<"f1 > f2 = "<<(f1>f2)<<endl;
    cout<<"f1 == f2 = "<<(f1==f2)<<endl;

    double value=f1;
    cout<<"Decimal value of f1 = "<<value<<endl;

    Fraction f3=2.75;
    cout<<"Fraction from 2.75 = "<<f3<<endl;

    return 0;
}