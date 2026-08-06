#include<iostream>
using namespace std;
float area(float l,float b)
{
	return l*b;
}
float perimeter(float l,float b)
{
	return 2*(l+b);
}
int main()
{
	float length,breadth;
	float A,P;
	cout << "Enter length: ";
	cin >> length;
	cout << "Enter breadth: ";
	cin >> breadth;
	A=area(length,breadth);
	P=perimeter(length,breadth);
	cout << "Area = " <<A <<endl;
	cout << "Perimeter = " <<P <<endl;
	return 0;
}
