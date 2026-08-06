#include<iostream>
using namespace std;
class Distance{
private:
	int feet;
	float inches;
public:
	Distance(int f=0,float i=0){
		feet=f;
		inches=i;
	}
	Distance operator-(){
		return Distance(-feet,-inches);
	}
	Distance operator++(){
		inches++;
		if(inches>=12){
			feet++;
			inches-=12;
		}
		return *this;
	}
	Distance operator++(int){
		Distance temp=*this;
		inches++;
		if(inches>=12){
			feet++;
			inches-=12;
		}
		return temp;
	}
	friend Distance operator*(Distance d,int n);
	friend Distance operator*(int n,Distance d);
	void display(){
		cout <<feet << " feet " <<inches << " inches";
	}
};
Distance operator*(Distance d,int n){
	float totalInches=(d.feet*12+d.inches)*n;
	Distance temp;
	temp.feet=totalInches/12;
	temp.inches=totalInches-temp.feet*12;
	return temp;
}
Distance operator*(int n,Distance d){
	return d*n;
}
int main()
{
	Distance d1(5,10),d2;
	cout << "Original Distance: ";
	d1.display();
	d2=-d1;
	cout << "\n\nAfter Unary (-): ";
	d2.display();
	++d1;
	cout << "\n\nAfter Prefix (++): ";
	d1.display();
	d1++;
	cout << "\n\nAfter Postfix (++): ";
	d1.display();
	d2=d1*2;
	cout << "\n\nDistance*2: ";
	d2.display();
	d2=3*d1;
	cout << "\n\n3*Distance: ";
	d2.display();
	return 0;
}
