#include <iostream>
using namespace std;

class Box {
private:
    float l, b, h;

public:
    Box() {
        l = 0.0;
        b = 0.0;
        h = 0.0;
        cout << "Default constructor called" << endl;
    }
};

int main() {
    Box b1;
    return 0;
}
