#include<iostream>
using namespace std;

    struct items
    {
      string name;
      float price ;
    };
    float bill(items i){
        return i.price*(0.13)+i.price;
    }
    int main(){
        items i;
        float a;
        cout<<"Enter name of item ";
        cin>>i.name;
        cout<<"Enter price of the item ";
        cin>>i.price;
      a =  bill (i);
      cout<<"the total bill is "<<a<<endl;
        
            return 0;
    }