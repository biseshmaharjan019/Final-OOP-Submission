#include<iostream>
using namespace std;

struct Item{
    string name;
    float price;
};

float calculateBill(Item i){
    return i.price + i.price*0.10;
}

int main(){
    Item i;
    cout<<"Item name: "; cin>>i.name;
    cout<<"Price: "; cin>>i.price;
    cout<<"Total bill: "<<calculateBill(i)<<endl;
    return 0;
}
