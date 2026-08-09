#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal speaks" << endl; }
};

class Dog : public Animal {
public:
    void speak() { cout << "Dog barks" << endl; }
};

class Cat : public Animal {
public:
    void speak() { cout << "Cat meows" << endl; }
};

int main() {
    Dog d;
    Cat c;

    Animal* ptr;

    ptr = &d;
    ptr->speak();
    ptr = &c;
    ptr->speak();

    // Output without virtual:
    // Animal speaks
    // Animal speaks
    // (Because speak() is not virtual, the compiler binds the call
    //  at compile time based on the pointer's type, Animal*, not
    //  the actual object it points to.)

    return 0;
}
