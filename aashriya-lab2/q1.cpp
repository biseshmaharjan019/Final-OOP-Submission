#include<iostream>
using namespace std;
int main(){
    int total=0,i;
    int sale[7];
    for(i=0;i<7;i++)
    {
        cout<<"Enter the sales of day "<<i+1<<": ";
        cin>>sale[i];
        total+=sale[i];
    }
    cout<<"Total sales for the week: "<<total<<endl;
    double average;
    average=total/7.0;
    cout<<"Average sales for the week: "<<average<<endl;    
    return 0;
}