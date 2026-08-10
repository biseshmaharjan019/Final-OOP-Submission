#include <iostream>
using namespace std;

template <typename T>
T max3(T a, T b, T c) {
    T m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

int main() {
    cout << "Max: " << max3(10, 20, 15) << endl;
    cout << "Max: " << max3(5.5f, 8.9f, 2.3f) << endl;
    cout << "Max: " << max3('a', 'm', 'z') << endl;
    return 0;
}
