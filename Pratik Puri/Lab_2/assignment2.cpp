#include <iostream>
using namespace std;
typedef struct{
    string name;
    string code;
    double price;
    int quantity;
}Product;
int main(){
    Product p[5];
    int i;
    for(i=0;i<5;i++){
        cout<<"Product "<<i+1<<endl;
        cout<<"Enter the name, code, price and quantity: ";
        cin>>p[i].name>>p[i].code>>p[i].price>>p[i].quantity;
    }
    for(i=0;i<5;i++){
        if(p[i].quantity < 10){
            cout<<"Name: "<<p[i].name<<endl<<"Code: "<<p[i].code<<"Price: "<<p[i].price<<endl<<"Quantity: "<<p[i].quantity;
        }
    }
    return 0;
}