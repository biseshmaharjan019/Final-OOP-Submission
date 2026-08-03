#include <iostream>
using namespace std;

template <typename T>
T max3(T a, T b, T c) {
    T max_val = a;
    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }
    return max_val;
}

int main() {
    cout << "Max of 10, 20, 15: " << max3(10, 20, 15) << endl;
    cout << "Max of 5.5, 8.9, 2.3: " << max3(5.5f, 8.9f, 2.3f) << endl;
    cout << "Max of 'a', 'm', 'z': " << max3('a', 'm', 'z') << endl;
    return 0;
}
