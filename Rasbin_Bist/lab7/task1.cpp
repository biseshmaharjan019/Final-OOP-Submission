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
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows: Meow! Meow!" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    Animal* ptr;   

    

    

    cout << "=== WITH virtual keyword (current run) ===" << endl;

    ptr = &dog;
    ptr->speak();   

    ptr = &cat;
    ptr->speak();   

    return 0;
}