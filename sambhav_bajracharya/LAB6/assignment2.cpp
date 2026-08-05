#include <iostream>
using namespace std;

class A {
private:
    int valA;

public:
    A(int a) {
        valA = a;
        cout << "Class A Constructor: " << valA << endl;
    }

    ~A() {
        cout << "Class A Destructor: " << valA << endl;
    }
};

class B : public A {
private:
    int valB;

public:
    B(int a, int b) : A(a) {
        valB = b;
        cout << "Class B Constructor: " << valB << endl;
    }

    ~B() {
        cout << "Class B Destructor: " << valB << endl;
    }
};

class C : public B {
private:
    int valC;

public:
    C(int a, int b, int c) : B(a, b) {
        valC = c;
        cout << "Class C Constructor: " << valC << endl;
    }

    ~C() {
        cout << "Class C Destructor: " << valC << endl;
    }
};

int main() {
    cout << "Creating obj1..." << endl;
    C obj1(1, 2, 3);

    cout << "\nCreating obj2..." << endl;
    C obj2(10, 20, 30);

    cout << "\nExiting main..." << endl;
    return 0;
}

/*
 * EXPECTED OUTPUT:
 * 
 * Creating obj1...
 * Class A Constructor: 1
 * Class B Constructor: 2
 * Class C Constructor: 3
 * 
 * Creating obj2...
 * Class A Constructor: 10
 * Class B Constructor: 20
 * Class C Constructor: 30
 * 
 * Exiting main...
 * Class C Destructor: 30
 * Class B Destructor: 20
 * Class A Destructor: 10
 * Class C Destructor: 3
 * Class B Destructor: 2
 * Class A Destructor: 1
 * 
 * Note: Constructing goes Base -> Derived (A -> B -> C).
 * Destructing goes Derived -> Base (C -> B -> A) in reverse order of allocation (LIFO).
 */
