//WAP to swap two numbers
#include<iostream>
using namespace std;
void swap(int a,int b)
{
   cout<< "Before swapping "<<a<<" "<<b<<endl;
   a=a+b;
   b=a-b;
   a=a-b;
   cout<< "After swapping "<<a<<" "<<b<<endl;
}
int main()
{
int a=7;
int b=9;
swap(a,b);

return 0;
}
