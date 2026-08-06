#include<iostream>
using namespace std;

void compute(int a,int b)
{
    try
    {
        if(b==0)
            throw "Division by zero";

        cout<<"Result = "<<a/b<<endl;
    }
    catch(const char *msg)
    {
        cout<<"compute(): Exception caught"<<endl;
        throw;
    }
}

int main()
{
    int a,b;

    cout<<"Enter two numbers: ";
    cin>>a>>b;

    try
    {
        compute(a,b);
    }
    catch(const char *msg)
    {
        cout<<"main(): Exception caught again"<<endl;
        cout<<"Message: "<<msg<<endl;
    }

    return 0;
}
