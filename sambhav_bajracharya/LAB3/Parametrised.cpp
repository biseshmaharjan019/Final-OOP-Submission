#include <iostream>
using namespace std;
class Box {
private:
    float l, b, h;

public:
    Box(float len, float bre, float hei) {
        l = len;
        b = bre;
        h = hei;
        cout << "Parameterised constructor called" << std::endl;
    }
};

int main() {
    Box b2(10.5f, 5.2f, 3.0f);
    return 0;
}
