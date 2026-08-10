#include <iostream>
using namespace std;

class A {
private:
    string n;
    int a;

public:
    A(string name, int age) : n(name), a(age) {}
    void showA() const {
        cout << "Name: " << n << "\nAge: " << a << endl;
    }
};

class M : virtual public A {
private:
    string f;

public:
    M(string name, int age, string fur) : A(name, age), f(fur) {}
    void showM() const { cout << "Fur: " << f << endl; }
};

class B : virtual public A {
private:
    float w;

public:
    B(string name, int age, float wing) : A(name, age), w(wing) {}
    void showB() const { cout << "Wingspan: " << w << "m" << endl; }
};

class Bat : public M, public B {
private:
    bool e;

public:
    Bat(string name, int age, string fur, float wing, bool echo)
        : A(name, age), M(name, age, fur), B(name, age, wing), e(echo) {}

    void show() const {
        showA();
        showM();
        showB();
        cout << "Echolocation: " << (e ? "Yes" : "No") << endl;
    }
};

int main() {
    Bat b("Bat", 3, "Black", 0.8, true);
    cout << "Bat Details:\n";
    b.show();
    return 0;
}

/*
Virtual inheritance prevents duplicate Animal base class copies
when Bat inherits from both Mammal and Bird, avoiding ambiguity.
*/
