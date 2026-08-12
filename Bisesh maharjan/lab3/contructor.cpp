#include<iostream>
using namespace std;

class Box {
    private:
        int l, b, h;

    public:
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }

        Box(int len, int bd, int ht) {
            l = len;
            b = bd;
            h = ht;
        }

        Box(int length) {
            l = length;
            b = 0;
            h = 0;
        }

        Box(Box &obj) {
            l = obj.l;
            b = obj.b;
            h = obj.h;
        }

        ~Box() {
            cout << "Object is destroyed" << endl;
        }

        void display() {
            cout << "L=" << l << "  B=" << b << "  H=" << h << endl;
        }
};

int main() {
    Box b1;
    cout << "b1: ";
    b1.display();

    Box b2(2, 3, 4);
    cout << "b2: ";
    b2.display();

    Box b3;
    cout << "b3: ";
    b3.display();

    Box b4(10);
    cout << "b4: ";
    b4.display();

    Box b5 = b4;
    cout << "b5: ";
    b5.display();

    return 0;
}
