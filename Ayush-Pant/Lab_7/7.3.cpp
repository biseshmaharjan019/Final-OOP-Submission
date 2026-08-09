#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() { cout << "Vehicle destructor called" << endl; }
    virtual string getType() { return "Vehicle"; }
};

class Car : public Vehicle {
    int numDoors;
public:
    Car(int d) { numDoors = d; }
    ~Car() { cout << "Car destructor called" << endl; }
    string getType() { return "Car"; }
    int getDoors() { return numDoors; }
};

class Truck : public Vehicle {
    float payloadTons;
public:
    Truck(float p) { payloadTons = p; }
    ~Truck() { cout << "Truck destructor called" << endl; }
    string getType() { return "Truck"; }
    float getPayload() { return payloadTons; }
};

int main() {
    Vehicle* vehicles[3];
    vehicles[0] = new Vehicle();
    vehicles[1] = new Car(4);
    vehicles[2] = new Truck(10.5);

    for (int i = 0; i < 3; i++) {
        Vehicle* ptr = vehicles[i];

        cout << "Actual type: " << typeid(*ptr).name() << endl;
        Car* carPtr = dynamic_cast<Car*>(ptr);
        if (carPtr != NULL) {
            cout << "It's a Car with " << carPtr->getDoors() << " doors" << endl;
        }
        Truck* truckPtr = dynamic_cast<Truck*>(ptr);
        if (truckPtr != NULL) {
            cout << "It's a Truck carrying " << truckPtr->getPayload() << " tons" << endl;
        }
        delete ptr;
        cout << " " << endl;
    }

    return 0;
}
