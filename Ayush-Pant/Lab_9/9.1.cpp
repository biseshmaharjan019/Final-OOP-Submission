#include <iostream>
#include <string>
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
    cout << "Maximum Integer: " << max3(10, 25, 15) << endl;
    cout << "Maximum Float: " << max3(4.5f, 7.8f, 2.1f) << endl;
    cout << "Maximum Character: " << max3('A', 'Z', 'M') << endl;

    return 0;
}
