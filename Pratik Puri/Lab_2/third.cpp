#include <iostream>
using namespace std;
float convert_currency(float one, float exchangerate){
    float another = one * exchangerate;
    return another;
}
int main(){
    float one, exchangerate;
    cout<<"Enter the currency amount: ";
    cin>>one;
    cout<<"Enter the exchange rate: ";
    cin>>exchangerate;
    cout<<"The converted currency is "<<convert_currency(one,exchangerate);

    return 0;
}