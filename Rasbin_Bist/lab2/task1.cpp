#include <iostream>
using namespace std;
int main(){

int sales[7];
int total=0,average;

for (int i =0;i<7;i++){
cout<<"Enter Sales of day"<<(i+1)<<"  23";
cin>>sales[i];
total+=sales[i];
}
average=total/7;
cout<<"the toal was:"<<total<<" & the average sale wa: "<<average<<endl;


    return 0;
}