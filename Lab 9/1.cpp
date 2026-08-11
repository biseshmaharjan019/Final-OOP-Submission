#include <iostream>
using namespace std;

template <typename T>
T max3(T a, T b, T c) {
    T maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    return maxVal;
}

int main() {
    int i1 = 10, i2 = 25, i3 = 15;
    cout << "Max of integers (" << i1 << ", " << i2 << ", " << i3 << "): " 
         << max3(i1, i2, i3) << endl;

    float f1 = 12.5f, f2 = 3.4f, f3 = 28.1f;
    cout << "Max of floats (" << f1 << ", " << f2 << ", " << f3 << "): " 
         << max3(f1, f2, f3) << endl;

    char c1 = 'a', c2 = 'z', c3 = 'm';
    cout << "Max of chars ('" << c1 << "', '" << c2 << "', '" << c3 << "'): " 
         << max3(c1, c2, c3) << endl;

    return 0;
}