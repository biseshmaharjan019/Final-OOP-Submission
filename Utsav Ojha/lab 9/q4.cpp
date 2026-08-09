#include <iostream>
using namespace std;

void compute(int a, int b)
{
    try
    {
        if(b == 0)
            throw "Divide by Zero";

        cout << "Result = " << a / b << endl;
    }
    catch(const char *msg)
    {
        cout << "Caught inside compute(): " << msg << endl;

        throw;
    }
}

int main()
{
    try
    {
        compute(20, 0);
    }
    catch(const char *msg)
    {
        cout << "Caught again in main(): " << msg << endl;
    }

    return 0;
}
