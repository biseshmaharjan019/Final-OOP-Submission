#include<iostream>
using namespace std;
void swap(int a,int b)
{
   cout<< "Before swapping a and b are "<<a<<" "<<b<<endl;
   a=a+b;
   b=a-b;
   a=a-b;
   cout<< "After swapping a and b are "<<a<<" "<<b<<endl;
}
int main()
{
int a=5;
int b=4;
swap(a,b);

return 0;
}