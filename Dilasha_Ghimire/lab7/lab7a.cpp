#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Cat meows" << std::endl;
    }
};

int main() {
    Dog dogObj;
    Cat catObj;
    Animal* ptr = nullptr;

    std::cout << "--- Calling speak() via Animal pointer ---" << std::endl;
    
    ptr = &dogObj;
    ptr->speak();

    ptr = &catObj;
    ptr->speak();

    return 0;
}

/*
Output without 'virtual' keyword in Animal::speak():
--- Calling speak() via Animal pointer ---
Animal speaks
Animal speaks

Output with 'virtual' keyword in Animal::speak():
--- Calling speak() via Animal pointer ---
Dog barks
Cat meows
*/
