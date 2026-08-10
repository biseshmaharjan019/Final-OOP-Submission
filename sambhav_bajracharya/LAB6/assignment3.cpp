#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    Animal(string n = "", int a = 0) {
        name = n;
        age = a;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Mammal : virtual public Animal {
private:
    string furColor;

public:
    Mammal(string n, int a, string f) : Animal(n, a) {
        furColor = f;
    }

    void display() const {
        cout << "Fur Color: " << furColor << endl;
    }
};

class Bird : virtual public Animal {
private:
    float wingspan;

public:
    Bird(string n, int a, float w) : Animal(n, a) {
        wingspan = w;
    }

    void display() const {
        cout << "Wingspan: " << wingspan << " ft" << endl;
    }
};

class Bat : public Mammal, public Bird {
private:
    bool echolocation;

public:
    Bat(string n, int a, string f, float w, bool echo) 
        : Animal(n, a), Mammal(n, a, f), Bird(n, a, w) {
        echolocation = echo;
    }

    void display() const {
        Animal::display();
        Mammal::display();
        Bird::display();
        cout << "Echolocation: " << (echolocation ? "Yes" : "No") << endl;
    }
};

int main() {
    /*
     * VIRTUAL INHERITANCE EXPLANATION:
     * Virtual inheritance is required here to solve the "Diamond Problem".
     * Without 'virtual public Animal', class Bat would inherit two separate instances 
     * of Animal (one via Mammal and another via Bird). This leads to ambiguity and duplicate data.
     * Declaring Animal as a virtual base class ensures that only a single, shared instance 
     * of Animal exists inside a Bat object.
     */

    Bat bat("Fruit Bat", 3, "Dark Brown", 1.5f, true);

    cout << "Bat Details" << endl;
    bat.display();

    return 0;
}
