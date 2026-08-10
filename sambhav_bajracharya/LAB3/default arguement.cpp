#include <iostream>
using namespace std;
class Box {
private:
    float l, b, h;

public:
    Box(float len = 1.0f, float bre = 1.0f, float hei = 1.0f) {
        l = len;
        b = bre;
        h = hei;
    	cout << "Constructor with default arguments called" << std::endl;
    }
};

int main() {
    Box b3;
    return 0;
}
