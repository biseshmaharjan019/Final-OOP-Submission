#include<iostream>
using namespace std;
class Complex{
private:
	float real,img;
public:
	Complex(float r=0,float i=0){
		real=r;
		img=i;
	}
	Complex operator+(Complex c){
		Complex temp;
		temp.real=real+c.real;
		temp.img=img+c.img;
		return temp;
	}
	Complex operator-(Complex c){
		Complex temp;
		temp.real=real-c.real;
		temp.img=img-c.img;
		return temp;
	}
	friend bool operator==(Complex c1,Complex c2);
	friend istream &operator>>(istream &in,Complex &c);
	friend ostream &operator<<(ostream &out,Complex &c);
};
bool operator==(Complex c1,Complex c2){
	return (c1.real==c2.real && c1.img==c2.img);
}
istream &operator>>(istream &in,Complex &c){
	cout <<"Enter real part: ";
	in >>c.real;
	cout <<"Enter imaginary part: ";
	in >>c.img;
	return in;
}
ostream &operator<<(ostream &out,Complex &c){
	if(c.img>=0){
		out <<c.real <<" + " <<c.img <<"i";
	}
	else{
		out <<c.real <<" - " <<-c.img <<"i";
	}
	return out;
}
int main()
{
	Complex c1,c2,sum,diff;
	cout << "Enter 1st complex number:\n";
	cin >> c1;
	cout << "\nEnter 2nd complex number:\n";
	cin >> c2;
	sum=c1+c2;
	diff=c1-c2;
	cout << "\n\nFirst complex number: " <<c1;
	cout << "\nSecond complex number: " <<c2;
	cout << "\n\nSum = " <<sum;
	cout << "\nDifference = " <<diff;
	if(c1==c2){
		cout << "\nBoth complex numbers are equal.";
	}
	else{
		cout << "\nBoth complex numbers are not equal.";
	}
	return 0;
}
