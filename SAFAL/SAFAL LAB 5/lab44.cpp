#include <iostream>
#include <cmath>
using namespace std;
class Fraction {
private:
    int num, den;
    void reduce() {
        int a = abs(num);
        int b = abs(den);
        while(b) {
            int t = a % b;
            a = b;
            b = t;
        }
        num /= a;
        den /= a;
        if(den < 0) {
            num = -num;
            den = -den;
        }
    }
public:
    Fraction(int n=0,int d=1) {
        num=n;
        den=d;
        reduce();
    }
    Fraction(double x) {
        den = 1000;
        num = round(x*1000);
        reduce();
    }
    operator double() const {
        return (double)num/den;
    }
    friend Fraction operator+(Fraction, Fraction);
    friend Fraction operator-(Fraction, Fraction);
    friend Fraction operator*(Fraction, Fraction);
    friend Fraction operator/(Fraction, Fraction);
    friend bool operator<(Fraction, Fraction);
    friend bool operator>(Fraction, Fraction);
    friend bool operator==(Fraction, Fraction);
    friend ostream& operator<<(ostream&, const Fraction&);
    friend istream& operator>>(istream&, Fraction&);
};
Fraction operator+(Fraction a,Fraction b){
    return Fraction(a.num*b.den+b.num*a.den,a.den*b.den);
}
Fraction operator-(Fraction a,Fraction b){
    return Fraction(a.num*b.den-b.num*a.den,a.den*b.den);
}
Fraction operator*(Fraction a,Fraction b){
    return Fraction(a.num*b.num,a.den*b.den);
}
Fraction operator/(Fraction a,Fraction b){
    return Fraction(a.num*b.den,a.den*b.num);
}
bool operator<(Fraction a,Fraction b){
    return a.num*b.den < b.num*a.den;
}
bool operator>(Fraction a,Fraction b){
    return a.num*b.den > b.num*a.den;
}
bool operator==(Fraction a,Fraction b){
    return a.num==b.num && a.den==b.den;
}
istream& operator>>(istream& in, Fraction& f){
    char slash;
    in>>f.num>>slash>>f.den;
    f.reduce();
    return in;
}
ostream& operator<<(ostream& out,const Fraction& f){
    out<<f.num<<"/"<<f.den;
    return out;
}
int main(){
    Fraction f1,f2;
    cout<<"Enter fractions (a/b): ";
    cin>>f1>>f2;
    cout<<"f1+f2 = "<<f1+f2<<endl;
    cout<<"f1-f2 = "<<f1-f2<<endl;
    cout<<"f1*f2 = "<<f1*f2<<endl;
    cout<<"f1/f2 = "<<f1/f2<<endl;
    cout<<"f1<f2 : "<<(f1<f2)<<endl;
    cout<<"f1>f2 : "<<(f1>f2)<<endl;
    cout<<"f1==f2 : "<<(f1==f2)<<endl;
    double d = f1;
    cout<<"Decimal of f1 = "<<d<<endl;
    Fraction f3 = 3.141;
    cout<<"Fraction from double = "<<f3<<endl;
    return 0;
}
