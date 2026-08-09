#include<iostream>
using namespace std;
int main(){
    int i,n,c=0,e=0,b=0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    for(i=1; i<=n; i++){
        int d=0;
        for(int j=1; j<=i; j++){
            if(i%j==0){
                 d++;
            }
        }
        if(d==2){
             e++;
        }
        else{
            b++;
        }
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
    cout<<"Number of prime numbers: "<<e<<endl;
    cout<<"Number of composite numbers: "<<b-1<<endl;
    return 0;
}