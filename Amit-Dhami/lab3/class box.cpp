#include<iostream>
using namespace std;
class Box
{
    float l,b,h;
public:
    Box()
    {
    l=b=h=0;
cout<<"Default Constructor Called\n";
    }
Box(float x,float y,float z)
    {
        l=x;
        b=y;
        h=z;
cout<<"Parameterized Constructor Called\n";
    }

    Box(Box &obj)
    {
        l=obj.l;
        b=obj.b;
        h=obj.h;
cout<<"Copy Constructor Called\n";
    }

    ~Box()
    {
        cout<<"Destructor Called\n";
    }
};
int main()
{
    Box b1;
    Box b2(2,3,4);
    Box b4=b2;
return 0;
}
