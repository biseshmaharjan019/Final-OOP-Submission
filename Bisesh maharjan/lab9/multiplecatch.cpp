#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException{
public:
    string message(){ return "Cannot divide by zero"; }
};

class NegativeDenominatorException{
public:
    string message(){ return "Denominator is negative"; }
};

int main(){
    float num, den;
    cout<<"Enter numerator: ";
    cin>>num;
    cout<<"Enter denominator: ";
    cin>>den;

    try{
        if(den==0) throw DivideByZeroException();
        if(den<0) throw NegativeDenominatorException();
        cout<<"Result: "<<num/den<<endl;
    } catch(DivideByZeroException e){
        cout<<e.message()<<endl;
    } catch(NegativeDenominatorException e){
        cout<<e.message()<<endl;
    } catch(...){
        cout<<"Unexpected exception occurred"<<endl;
    }

    return 0;
}
