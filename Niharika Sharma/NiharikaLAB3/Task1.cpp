#include<iostream>
using namespace std;
class Box
{
private:
	float l,b,h;
public:
	Box()
	{
		l=b=h=0;
		cout << "Default Constructor called" <<endl;
	}		
	Box(float x,float y,float z)
	{
		l=x;
		b=y;
		h=z;
		cout << "Parameterized Constructor called" <<endl;
	}
Box(float x=1,float y=10,float z=3)
	{
		l=x;
		b=y;
		h=z;
		cout << "Constructor with default arguments called" <<endl;
	}
	Box(const Box &obj)
	{
		l=obj.l;
		b=obj.b;
		h=obj.h;
	}
	~Box()
	{
		cout << "Destructor called. Object destroyed." <<endl;
	}		
}; 
int main()
{
	cout << "\nCreating object b1: " <<endl;
	Box b1;
	cout << "\nCreating object b2: " <<endl;
	Box b2(2,4,6);
	cout << "\nCreating object b3: " <<endl;
	Box b3;
	cout << "\nCreating object b4: " <<endl;
	Box b4(b2);
	return 0;
}
