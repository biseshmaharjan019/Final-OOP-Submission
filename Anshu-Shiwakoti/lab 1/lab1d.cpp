#include<iostream>
using namespace std;
int main(){
    int i,n,c=0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(i=1; i<=n; i++){
        if(n%i==0){
            c++;    
        }
    }
    if(c==2){
        cout<<"The number is prime"<<endl;
    }
    else{
        cout<<"The number is not prime"<<endl;
    }
    return 0;
}