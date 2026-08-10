#include<iostream>
using namespace std;
void swap(int &x, int &y){
    x=x+y;
    y=x-y;
    x=x-y;
}
int main()
{
    int a, b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    cout<<"Before swapping: "<<a<<" "<<b<<endl;
    swap(a, b);
    cout<<"After swapping: "<<a<<" "<<b<<endl;
    return 0;
}