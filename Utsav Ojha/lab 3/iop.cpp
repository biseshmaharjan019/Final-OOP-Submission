#include<iostream>
using namespace std;

class Animal
{
    public:
        void eat()
        {
            cout<<"Animal is eating";
        }
};

class Dog : public Animal
{
    public:
        void bark()
        {
            cout<<"\nDog is barking";
        }
};

int main()
{
    Dog d;

    d.eat();
    d.bark();

    return 0;
}