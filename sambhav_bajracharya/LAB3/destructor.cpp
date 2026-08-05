#include <iostream>
using namespace std;
class Box {
private:
    float l, b, h;

public:
    Box() {
        l = 0.0f;
        b = 0.0f;
        h = 0.0f;
    }

    void destroy() {
        cout << "Destructor called: Object is destroyed" << std::endl;
    }
};

int main() {
    Box b5;

    b5.destroy();

    return 0;
}
