#include<iostream>
using namespace std;

class DivideByZeroException
{
public:
    string message()
    {
        return "Division by zero is not allowed.";
    }
};

class NegativeDenominatorException
{
public:
    string message()
    {
        return "Denominator cannot be negative.";
    }
};

int main()
{
    double a,b;

    cout<<"Enter numerator: ";
    cin>>a;

    cout<<"Enter denominator: ";
    cin>>b;

    try
    {
        if(b==0)
            throw DivideByZeroException();

        if(b<0)
            throw NegativeDenominatorException();

        cout<<"Result = "<<a/b<<endl;
    }
    catch(DivideByZeroException e)
    {
        cout<<"Exception: "<<e.message()<<endl;
    }
    catch(NegativeDenominatorException e)
    {
        cout<<"Exception: "<<e.message()<<endl;
    }
    catch(...)
    {
        cout<<"Exception: Unexpected error."<<endl;
    }

    return 0;
}
