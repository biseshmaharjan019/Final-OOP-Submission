#include <iostream>
#include<string>
using namespace std;
class Animal
{
    public:
    virtual void speak()
    {
        cout<<"animal speaks"<<endl;
    }
};
class Dog:public Animal{
    public:
    void speak(){
        cout<<"dog barks"<<endl;
    }
};
class Cat:public Animal{
    public:
    void speak(){
        cout<<"cat"<<endl;
    }
};
int main() {
    Dog d;
    Cat c;
    Animal *ptr;
    cout << "Without virtual function:" << endl;
    ptr = &d;
    ptr->speak();
    ptr = &c;
    ptr->speak();
    return 0;
}
