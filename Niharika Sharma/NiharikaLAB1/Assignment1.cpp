#include<iostream>
using namespace std;
int swap(int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
int main()
{
	int a,b,Swap;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	cout << "Before swapping :" <<endl;
	cout << "a=" << a << ",b=" << b <<endl;
	Swap=swap(a,b);
	cout << "After swapping :" <<endl;
	cout << "a=" << a << ",b=" << b <<endl;
	return 0;
}
