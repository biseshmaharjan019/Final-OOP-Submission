// Swap Two Numbers Using Function

#include <iostream>
using namespace std;

void swapNum(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    swapNum(a, b);

    cout << "After swapping: " << a << " " << b << endl;

    system("pause");
    return 0;
}