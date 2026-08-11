//swapping the two numbers without using temp variable
#include <iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    a = a+b;
    b = a-b;
    a = a-b;
    cout<<a<<" "<<b;
}