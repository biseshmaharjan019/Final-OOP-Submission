#include <iostream>

template <typename T>
T max3(T a, T b, T c) {
    T maxVal = a;
    if (b > maxVal) {
        maxVal = b;
    }
    if (c > maxVal) {
        maxVal = c;
    }
    return maxVal;
}

int main() {
    int i1 = 15, i2 = 42, i3 = 28;
    std::cout << "Max Int: " << max3(i1, i2, i3) << std::endl;

    float f1 = 3.14f, f2 = 9.81f, f3 = 2.71f;
    std::cout << "Max Float: " << max3(f1, f2, f3) << std::endl;

    char c1 = 'a', c2 = 'z', c3 = 'm';
    std::cout << "Max Char: " << max3(c1, c2, c3) << std::endl;

    return 0;
}