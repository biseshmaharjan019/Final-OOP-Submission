#include <iostream>
using namespace std;

class DivideByZeroException
{
public:
    const char* message()
    {
        return "Error: Division by Zero";
    }
};

class NegativeDenominatorException
{
public:
    const char* message()
    {
        return "Error: Negative Denominator";
    }
};

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    try
    {
        if(b == 0)
            throw DivideByZeroException();

        if(b < 0)
            throw NegativeDenominatorException();

        cout << "Result = " << a / b << endl;
    }
    catch(DivideByZeroException e)
    {
        cout << e.message() << endl;
    }
    catch(NegativeDenominatorException e)
    {
        cout << e.message() << endl;
    }
    catch(...)
    {
        cout << "Unknown Exception" << endl;
    }

    return 0;
}
