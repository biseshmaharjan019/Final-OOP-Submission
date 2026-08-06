#include <iostream>
using namespace std;
class A {
public:
    A(int x) {
        cout << "Constructor A" << endl;
    }
    ~A() {
        cout << "Destructor A" << endl;
    }
};
class B : public A {
public:
    B(int x, int y) : A(x) {
        cout << "Constructor B" << endl;
    }
    ~B() {
        cout << "Destructor B" << endl;
    }
};
class C : public B {
public:
    C(int x, int y, int z) : B(x, y) {
        cout << "Constructor C" << endl;
    }
    ~C() {
        cout << "Destructor C" << endl;
    }
};
int main() {
    C obj1(10, 20, 30);
    cout << endl;
    C obj2(40, 50, 60);
    return 0;
}
