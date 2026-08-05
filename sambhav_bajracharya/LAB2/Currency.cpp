//WAP to enter amount and rate and then convert currency
#include<iostream>
using namespace std;
float convertCurrency(float,float);
int main()
{
    float a,r;
    cout<<"Enter amount and rate:";
    cin>>a>>r;
    cout<<"converted amount = "<<convertCurrency(a, r);
    return 0;
}
float convertCurrency(float amt, float rate)
{
    return amt * rate;
}
