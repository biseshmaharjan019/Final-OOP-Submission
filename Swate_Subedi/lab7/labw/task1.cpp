#include <iostream>
using namespace std;

class A1 {
public:
    void s() { cout << "Animal speaks" << endl; }
};

class D1 : public A1 {
public:
    void s() { cout << "Dog barks" << endl; }
};

class C1 : public A1 {
public:
    void s() { cout << "Cat meows" << endl; }
};

class A2 {
public:
    virtual void s() { cout << "Animal speaks" << endl; }
};

class D2 : public A2 {
public:
    void s() override { cout << "Dog barks" << endl; }
};

class C2 : public A2 {
public:
    void s() override { cout << "Cat meows" << endl; }
};

int main() {
    D1 d1; C1 c1; A1* p1;
    cout << "Without virtual:\n";
    p1 = &d1; p1->s();
    p1 = &c1; p1->s();

    D2 d2; C2 c2; A2* p2;
    cout << "\nWith virtual:\n";
    p2 = &d2; p2->s();
    p2 = &c2; p2->s();

    return 0;
}
