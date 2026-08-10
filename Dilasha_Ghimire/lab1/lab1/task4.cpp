#include<iostream>
using namespace std;

void swap(int a, int b){
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"After swap: a="<<a<<" b="<<b<<endl;
}
int main(){
    int a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    swap(a, b);
    return 0;
}