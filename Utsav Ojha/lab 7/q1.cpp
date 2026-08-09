#include<iostream>
using namespace std;

class Animal{
public:
    virtual void speak()      // Remove virtual to see base class output
    {
        cout<<"Animal speaks"<<endl;
    }
};

class Dog:public Animal{
public:
    void speak()
    {
        cout<<"Dog barks"<<endl;
    }
};

class Cat:public Animal{
public:
    void speak()
    {
        cout<<"Cat meows"<<endl;
    }
};

int main()
{
    Animal *p;

    Dog d;
    Cat c;

    p=&d;
    p->speak();

    p=&c;
    p->speak();

    return 0;
}

/*
Without virtual:
Animal speaks
Animal speaks

With virtual:
Dog barks
Cat meows

Virtual function enables runtime polymorphism.
*/