#include<iostream>
using namespace std;
class Fraction{
private:
	int numerator,denominator;
public:
	Fraction(int n=0,int d=0){
		numerator=n;
		denominator=d;
	}
	void input(){
		cout << "Enter numerator: ";
		cin >> numerator;
		cout << "Enter denominator: ";
		cin >> denominator;
	}
	void display(){
		cout << numerator << "/" << denominator ;
	}
	Fraction operator+(Fraction f){
		Fraction temp;
		temp.numerator=numerator*f.denominator+f.numerator*denominator;
		temp.denominator=denominator*f.denominator;
		return temp;
	}
	Fraction operator-(Fraction f){
		Fraction temp;
		temp.numerator=numerator*f.denominator-f.numerator*denominator;
		temp.denominator=denominator*f.denominator;
		return temp;
	}
	bool operator==(Fraction f){
		return (numerator*f.denominator==f.numerator*denominator);
	}
};
int main()
{
	Fraction f1,f2,sum,diff;
	cout << "Enter 1st fraction:\n";
	f1.input();
	cout << "\nEnter 2nd fraction:\n";
	f2.input();
	sum=f1+f2;
	diff=f1-f2;
	cout << "\nFirst fraction: ";
	f1.display();
	cout << "\nSecond fraction: ";
	f2.display();
	cout << "\n\nSum = ";
	sum.display();
	cout << "\nDifference = ";
	diff.display();
	if(f1==f2){
		cout << "\n\nBoth fractions are equal.";
	}
	else{
		cout << "\n\nBoth fractions are not equal.";
	}
	return 0;
}
