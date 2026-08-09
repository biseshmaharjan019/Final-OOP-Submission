#include<iostream>
using namespace std;

float convertCurrency(float amount, float rate){
    return amount*rate;
}

int main(){
    float amount, rate;
    cout<<"Amount: "; cin>>amount;
    cout<<"Rate: "; cin>>rate;
    cout<<"Converted: "<<convertCurrency(amount,rate)<<endl;
    return 0;
}
