#include <iostream>
using namespace std;
template <class T>
T max3(T a, T b, T c)
{
    T maximum = a;

    if (b > maximum)
        maximum = b;

    if (c > maximum)
        maximum = c;

    return maximum;
}

int main()
{
    cout << "Maximum of integers: "
         << max3(10, 25, 15) << endl;

    cout << "Maximum of floats: "
         << max3(10.5f, 25.7f, 15.2f) << endl;

    cout << "Maximum of characters: "
         << max3('A', 'Z', 'M') << endl;

    return 0;
}
