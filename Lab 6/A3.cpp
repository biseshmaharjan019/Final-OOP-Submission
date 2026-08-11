#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    Animal(string n = "", int a = 0) : name(n), age(a) {}

    void displayAnimal() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Mammal : virtual public Animal {
private:
    string furColor;

public:
    Mammal(string n, int a, string fur) : Animal(n, a), furColor(fur) {}

    void displayMammal() const {
        cout << "Fur Color: " << furColor << endl;
    }
};

class Bird : virtual public Animal {
private:
    float wingSpan;

public:
    Bird(string n, int a, float wing) : Animal(n, a), wingSpan(wing) {}

    void displayBird() const {
        cout << "Wing Span: " << wingSpan << " meters" << endl;
    }
};
class Bat : public Mammal, public Bird {
private:
    bool isNocturnal;

public:
    Bat(string n, int a, string fur, float wing, bool nocturnal)
        : Animal(n, a), Mammal(n, a, fur), Bird(n, a, wing), isNocturnal(nocturnal) {}

    void display() const {
        displayAnimal();
        displayMammal();
        displayBird();
        cout << "Is Nocturnal: " << (isNocturnal ? "Yes" : "No") << endl;
    }
};

int main() {
    Bat b("Fruit Bat", 3, "Brown", 1.2f, true);

    cout << "Bat Details (Hybrid Inheritance)" << endl;
    b.display();

    return 0;
}