#include<iostream>
using namespace std;

int main(){
    float sales[7], total=0;
    for(int i=0; i<7; i++){
        cout<<"Day "<<i+1<<": ";
        cin>>sales[i];
        total+=sales[i];
    }
    cout<<"Total: "<<total<<endl;
    cout<<"Average: "<<total/7<<endl;
    return 0;
}
