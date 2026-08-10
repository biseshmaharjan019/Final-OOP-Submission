// Vehicle Polymorphism, RTTI (dynamic_cast / typeid), and Virtual Destructors

#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>
using namespace std;

class Vehicle
{
public:
    virtual ~Vehicle()
    {
        cout << "Vehicle destructor called" << endl;
    }

    virtual string getType() const
    {
        return "Vehicle";
    }
};

class Car : public Vehicle
{
    int numDoors;

public:
    Car(int d) : numDoors(d) {}

    int getDoors() const
    {
        return numDoors;
    }

    ~Car() override
    {
        cout << "Car destructor called" << endl;
    }

    string getType() const override
    {
        return "Car";
    }
};

class Truck : public Vehicle
{
    float payloadTons;

public:
    Truck(float p) : payloadTons(p) {}

    float getPayload() const
    {
        return payloadTons;
    }

    ~Truck() override
    {
        cout << "Truck destructor called" << endl;
    }

    string getType() const override
    {
        return "Truck";
    }
};

int main()
{
    Vehicle *a[3] = {new Vehicle(), new Car(4), new Truck(8.5f)};

    for (int i = 0; i < 3; i++)
    {
        cout << "\nObject " << i + 1 << endl;
        cout << "getType(): " << a[i]->getType() << endl;
        cout << "typeid name: " << typeid(*a[i]).name() << endl;

        Car *c = dynamic_cast<Car *>(a[i]);
        if (c)
        {
            cout << "Car doors: " << c->getDoors() << endl;
        }

        Truck *t = dynamic_cast<Truck *>(a[i]);
        if (t)
        {
            cout << "Truck payload: " << t->getPayload() << " tons" << endl;
        }

        delete a[i];
    }

    system("pause");
    return 0;
}