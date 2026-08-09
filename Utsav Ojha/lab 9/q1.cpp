#include <iostream>
using namespace std;

template <class T>
T max3(T a, T b, T c)
{
    T max = a;

    if(b > max)
        max = b;

    if(c > max)
        max = c;

    return max;
}

int main()
{
    cout << "Maximum Integer = " << max3(10, 20, 15) << endl;
    cout << "Maximum Float = " << max3(2.5f, 8.6f, 4.3f) << endl;
    cout << "Maximum Character = " << max3('A', 'Z', 'M') << endl;

    return 0;
}
