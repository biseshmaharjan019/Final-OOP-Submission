#include <iostream>
using namespace std;
class A {
protected:
    int a;
public:
    A(int x) {
        a = x;
        cout << "A Constructor: " << a << endl;
    }
    ~A() {
        cout << "A Destructor: " << a << endl;
    }
};
class B : public A {
protected:
    int b;
public:
    B(int x, int y)
        : A(x) {
        b = y;
        cout << "B Constructor: " << b << endl;
    }

    ~B() {
        cout << "B Destructor: " << b << endl;
    }
};
class C : public B {
private:
    int c;
public:
    C(int x, int y, int z)
        : B(x, y) {
        c = z;
        cout << "C Constructor: " << c << endl;
    }
    ~C() {
        cout << "C Destructor: " << c << endl;
    }
};
int main() {
    C obj1(1, 2, 3);
    cout << endl;
    C obj2(10, 20, 30);
    return 0;
}
