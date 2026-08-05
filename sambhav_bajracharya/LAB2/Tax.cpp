#include<iostream>
using namespace std;
struct item 
{
    char name[20];
    int price;
};
void calculateBill(item i);
int main() 
{
    struct item i;
    cout<<"Enter order and price:";
    cin>>i.name>>i.price;
    calculateBill(i);
    return 0;
}
void calculateBill(item i) 
{
    float final; 
    final=i.price+(0.1*i.price);
    cout<<"Final price: "<<final<<endl;
}
