#include <iostream>
using namespace std;

int compute(int a, int b){
    try{
        if(b==0) throw "Division by zero";
        return a/b;
    } catch(const char *msg){
        cout<<"Caught in compute(): "<<msg<<endl;
        throw;
    }
}

int main(){
    int a=10, b=0;
    try{
        int result = compute(a,b);
        cout<<"Result: "<<result<<endl;
    } catch(const char *msg){
        cout<<"Caught in main(): "<<msg<<endl;
    }
    return 0;
}
