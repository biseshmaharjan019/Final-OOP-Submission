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
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Dog dogObj;
    Cat catObj;
    Animal* ptr;

    ptr = &dogObj;
    ptr->speak();

    ptr = &catObj;
    ptr->speak();

    return 0;
}