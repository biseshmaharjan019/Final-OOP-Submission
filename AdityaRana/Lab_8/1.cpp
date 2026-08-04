#include <iostream>
using namespace std;

template <class T>
T max3(T a, T b, T c)
{
    T max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int main()
{
    cout << "Maximum Integer: " << max3(11,15, 45) << endl;
    cout << "Maximum Float: " << max3(3.5f, 8.9f, 7.6f) << endl;
    cout << "Maximum Character: " << max3('A', 'Z', 'M') << endl;

    return 0;
}