#include<iostream>
using namespace std;
int main(){
     int n,i,j,count=0,s=0,p=0;
     cout<<"Enter a number"<<endl;
     cin>>n;
     for(i=1;i<=n;i++){
        count=0;
        for(j=1;j<=i;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==2){
            s++;
        }
        else{
            p++;
        }
     }
     cout<<"number of prime"<<s<<endl;
     cout<<"number of composite"<<p<<endl;
}