#include<iostream>
#include <typeinfo>
using namespace std;
class Vehicle
{
public:
    virtual ~Vehicle()
    {
        cout << "Vehicle Destructor Called" << endl;
    }

    virtual string getType()
    {
        return "Vehicle";
    }
};

class Car : public Vehicle
{
    int numDoors;

public:
    Car(int d)
    {
        numDoors = d;
    }

    ~Car()
    {
        cout << "Car Destructor Called" << endl;
    }

    string getType()
    {
        return "Car";
    }

    int getDoors()
    {
        return numDoors;
    }
};

class Truck : public Vehicle
{
    float payloadTons;

public:
    Truck(float p)
    {
        payloadTons = p;
    }

    ~Truck()
    {
        cout << "Truck Destructor Called" << endl;
    }

    string getType()
    {
        return "Truck";
    }

    float getPayload()
    {
        return payloadTons;
    }
};

int main()
{
    Vehicle *v[3];

    v[0] = new Vehicle();
    v[1] = new Car(3);
    v[2] = new Truck(10.5);

    for (int i = 0; i < 3; i++)
    {
        cout << "Runtime Type: " << typeid(*v[i]).name() << endl;

        Car *c = dynamic_cast<Car *>(v[i]);
        if (c != NULL)
            cout << "Number of Doors: " << c->getDoors() << endl;

        Truck *t = dynamic_cast<Truck *>(v[i]);
        if (t != NULL)
            cout << "Payload: " << t->getPayload() << " tons" << endl;

        delete v[i];
        cout << endl;
    }



    return 0;
}