//WAP to find the area and perimeter using two seperate functions
#include<iostream>
using namespace std;
void peri(int,int);
void area(int,int);
int main()
{
	int l,b;
	cout<<"enter the length and breadth";
	cin>>l>>b;
	peri(l,b);
	area(l,b);
	return 0;
}
void peri(int l, int b)
{
	cout<<"perimeter= "<<2*(l+b)<<endl;
}
void area(int l, int b)
{
	cout<<"area= "<<l*b;
}
