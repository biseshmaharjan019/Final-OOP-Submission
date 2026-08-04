#include<iostream>
using namespace std;
float area(float l, float b){
    return l*b;
}
float perimeter(float l, float b){
    return 2*(l+b);
}
int main(){
    int l, b;
    cout<<"Enter length and breadth"<<endl;
    cin>>l>>b;
    cout<<"Area of rectangle is: "<<area(l,b)<<endl;
    cout<<"Perimeter of rectangle is: "<<perimeter(l,b)<<endl;
    return 0;
}