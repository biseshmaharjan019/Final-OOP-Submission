// wap with function that takes two argument as refrence and assign the avg of the two argument
//  to the greater one and return that by reference. call this function by assigning  value to the
//  function and display the value of the function
#include <iostream>
using namespace std;
int &avvg(int &a, int &b)
{
    if (a > b)
    {
        a = (a + b) / 2;
        return a;
    }
    else
    {
        b = (a + b) / 2;
        return b;
    }
}
int main()
{
    int x, y;
    cout << "Enter the two numbers:";
    cin >> x >> y;
    cout << avvg(x, y);

    return 0;
}