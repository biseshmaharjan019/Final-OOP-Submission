#include <iostream>
using namespace std;

class A {
private:
    int x;

public:
    A(int a) : x(a) {
        cout << "A ctor: " << x << endl;
    }
    ~A() {
        cout << "A dtor: " << x << endl;
    }
};

class B : public A {
private:
    int y;

public:
    B(int a, int b) : A(a), y(b) {
        cout << "B ctor: " << y << endl;
    }
    ~B() {
        cout << "B dtor: " << y << endl;
    }
};

class C : public B {
private:
    int z;

public:
    C(int a, int b, int c) : B(a, b), z(c) {
        cout << "C ctor: " << z << endl;
    }
    ~C() {
        cout << "C dtor: " << z << endl;
    }
};

int main() {
    /*
    Expected:
    For each C object:
    Construction: A -> B -> C
    Destruction:  C -> B -> A (reverse)
    Objects destroyed in reverse creation order.
    */

    cout << "First object:\n";
    C o1(10, 20, 30);

    cout << "\nSecond object:\n";
    C o2(40, 50, 60);

    cout << "\nEnd main\n";
    return 0;
}
