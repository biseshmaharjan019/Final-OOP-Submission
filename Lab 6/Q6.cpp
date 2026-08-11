// Virtual Inheritance and Diamond Problem Resolution

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Animal
{
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    void displayAnimal() const
    {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Mammal : virtual public Animal
{
    string furColor;

public:
    Mammal(string n, int a, string f) : Animal(n, a), furColor(f) {}

    string getFurColor() const
    {
        return furColor;
    }
};

class Bird : virtual public Animal
{
    float wingspan;

public:
    Bird(string n, int a, float w) : Animal(n, a), wingspan(w) {}

    float getWingspan() const
    {
        return wingspan;
    }
};

class Bat : public Mammal, public Bird
{
    bool echolocation;

public:
    Bat(string n, int a, string f, float w, bool e)
        : Animal(n, a), Mammal(n, a, f), Bird(n, a, w), echolocation(e) {}

    void display() const
    {
        displayAnimal();
        cout << "Fur Color: " << getFurColor() << endl;
        cout << "Wingspan: " << getWingspan() << " m" << endl;
        cout << "Echolocation: " << (echolocation ? "Yes" : "No") << endl;
    }
};

int main()
{
    Bat b("Bat", 3, "Black", 0.35f, true);
    b.display();

    system("pause");
    return 0;
}