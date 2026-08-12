#include<iostream>
using namespace std;
int perimeter(int a,int b)
{
    cout<<"The perimeter is "<<2*(a+b)<<endl;
}
int area(int a,int b)
{
    cout<<"The area is "<<a*b <<endl;
}
 int main()
 {
    int l,b;
    cout<<"Enter the length and breadth"<<endl;
cin>>l>>b;
perimeter(l,b);
area(l,b);
return 0;
 }
