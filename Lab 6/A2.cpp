#include <iostream>
using namespace std;

class A {
private:
    int valA;

public:
    A(int a) : valA(a) {
        cout << "Class A Constructor called (valA = " << valA << ")" << endl;
    }

    ~A() {
        cout << "Class A Destructor called" << endl;
    }
};

class B : public A {
private:
    int valB;

public:
    B(int a, int b) : A(a), valB(b) {
        cout << "Class B Constructor called (valB = " << valB << ")" << endl;
    }

    ~B() {
        cout << "Class B Destructor called" << endl;
    }
};

class C : public B {
private:
    int valC;

public:
    C(int a, int b, int c) : B(a, b), valC(c) {
        cout << "Class C Constructor called (valC = " << valC << ")" << endl;
    }

    ~C() {
        cout << "Class C Destructor called" << endl;
    }
};

int main() {
    cout << " Creating Object c1 " << endl;
    C c1(10, 20, 30);

    cout << "\n Creating Object c2 " << endl;
    C c2(100, 200, 300);

    cout << "\n Exiting main (Destruction Phase) " << endl;
    return 0;
}
