#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows: Meow!" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    Animal* ptr;

    ptr = &dog;
    ptr->speak();

    ptr = &cat;
    ptr->speak();

    return 0;
}

/*
 * OUTPUT WITHOUT 'virtual':
 * Animal speaks
 * Animal speaks
 * 
 * OUTPUT WITH 'virtual':
 * Dog barks: Woof!
 * Cat meows: Meow!
 * 
 * EXPLANATION:
 * Without 'virtual', C++ uses early binding (static resolution at compile time). 
 * The compiler looks at the pointer type (Animal*) and calls Animal::speak().
 * 
 * With 'virtual', C++ uses late binding (dynamic resolution at runtime via vtable). 
 * The program inspects the actual object type being pointed to and calls the 
 * overridden function of that specific object.
 */
