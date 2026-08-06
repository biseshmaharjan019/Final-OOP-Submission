#include<iostream>
using namespace std;
class Animal{
public:
    void speak()
    {
        cout << "Animal speaks" <<endl;
    }
};
class Dog:public Animal{
public:
    void speak(){
        cout << "Dog barks" <<endl;
    }
};
class Cat:public Animal{
public:
    void speak(){
        cout << "Cat meows" <<endl;
    }
};
int main()
{
    Animal *ptr;
    Dog d;
    Cat c;
    cout << "Without Virtual Function:\n";
    ptr=&d;
    ptr->speak();
    ptr=&c;
    ptr->speak();
    return 0;
}

/*
//Using Virtual Function
#include<iostream>
using namespace std;
class Animal{
public:
    virtual void speak()
    {
        cout << "Animal speaks" <<endl;
    }
};
class Dog:public Animal{
public:
    void speak(){
        cout << "Dog barks" <<endl;
    }
};
class Cat:public Animal{
public:
    void speak(){
        cout << "Cat meows" <<endl;
    }
};
int main()
{
    Animal *ptr;
    Dog d;
    Cat c;
    cout << "With Virtual Function:\n";
    ptr=&d;
    ptr->speak();
    ptr=&c;
    ptr->speak();
    return 0;
}
*/
