#include <iostream>
using namespace std;

class Animal {
public:
    void speak() { cout << "Animal speaks" << endl; }
};
class Dog : public Animal { public: void speak() { cout << "Dog barks" << endl; } };
class Cat : public Animal { public: void speak() { cout << "Cat meows" << endl; } };

class VirtualAnimal {
public:
    virtual void speak() { cout << "Animal speaks" << endl; }
    virtual ~VirtualAnimal() {}
};
class VirtualDog : public VirtualAnimal { public: void speak() override { cout << "Dog barks" << endl; } };
class VirtualCat : public VirtualAnimal { public: void speak() override { cout << "Cat meows" << endl; } };

int main() {
    /* Non-virtual output:
       Animal speaks
       Animal speaks
       The base version is called because non-virtual functions use static binding.

       Virtual output:
       Dog barks
       Cat meows
       The virtual keyword enables dynamic binding, so the actual object's function runs.
    */
    Dog dog; Cat cat; Animal* p;
    cout << "NON-VIRTUAL VERSION:" << endl;
    p=&dog; p->speak(); p=&cat; p->speak();
    cout << "\nVIRTUAL VERSION:" << endl;
    VirtualDog vdog; VirtualCat vcat; VirtualAnimal* vp;
    vp=&vdog; vp->speak(); vp=&vcat; vp->speak();
    system("pause"); return 0;
}
