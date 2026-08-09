#include <iostream>
using namespace std;
typedef struct{
    string name;
    double price;
}claculateBill;
void calc_Bill(claculateBill b){
    double total = b.price + 0.1*b.price;
    cout<<b.name<<endl;
    cout<<"Your total is "<<total<<endl;
    
}
int main(){
    claculateBill b;
    string name;
    double price;
    cout<<"Enter the name for the bill: ";
    cin>>b.name;
    cout<<"Enter the price: ";
    cin>>b.price;
    calc_Bill(b);

}