#include<iostream>
using namespace std;
float convertCurrenct(float amount,float rate){
    return amount*rate;
}
int main (){
int amount ,rate;
cout<<"Enter amount and rate ";
cin>>amount>>rate;
cout<<"The exchanged rate is "<<convertCurrenct(amount,rate)<<endl;

return 0;

}