#include <iostream>
using namespace std;

template <class T>
T max3(T a, T b, T c) {
    T largest = a;

    if (b > largest)
        largest = b;

    if (c > largest)
        largest = c;

    return largest;
}

int main() {
    int a = 10, b = 25, c = 15;
    float x = 4.5f, y = 8.2f, z = 6.7f;
    char p = 'A', q = 'Z', r = 'M';

    cout << "Maximum of integers: "
         << max3(a, b, c) << endl;

    cout << "Maximum of floats: "
         << max3(x, y, z) << endl;

    cout << "Maximum of characters: "
         << max3(p, q, r) << endl;

    system("pause");
    return 0;
}
