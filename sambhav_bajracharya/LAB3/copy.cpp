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
    }

    Box(const Box &obj) {
        l = obj.l;
        b = obj.b;
        h = obj.h;
        cout << "Copy constructor called" << std::endl;
    }
};

int main() {
    Box b_source(4.5f, 3.2f, 1.2f);
    Box b4 = b_source;
    return 0;
}
