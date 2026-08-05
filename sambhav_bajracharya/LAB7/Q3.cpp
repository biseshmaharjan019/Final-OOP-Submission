#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual string getType() const {
        return "Vehicle";
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called." << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(int doors) {
        numDoors = doors;
    }

    string getType() const override {
        return "Car";
    }

    int getDoors() const {
        return numDoors;
    }

    ~Car() override {
        cout << "Car destructor called." << endl;
    }
};

class Truck : public Vehicle {
private:
    float payloadTons;

public:
    Truck(float payload) {
        payloadTons = payload;
    }

    string getType() const override {
        return "Truck";
    }

    float getPayload() const {
        return payloadTons;
    }

    ~Truck() override {
        cout << "Truck destructor called." << endl;
    }
};

int main() {
    Vehicle* vehicles[3];
    vehicles[0] = new Vehicle();
    vehicles[1] = new Car(4);
    vehicles[2] = new Truck(12.5f);

    for (int i = 0; i < 3; i++) {
        cout << "\nVehicle " << i + 1 << endl;

        cout << "Runtime Type Name: " << typeid(*vehicles[i]).name() << endl;

        Car* carPtr = dynamic_cast<Car*>(vehicles[i]);
        if (carPtr) {
            cout << "Successfully cast to Car. Number of doors: " << carPtr->getDoors() << endl;
        }

        Truck* truckPtr = dynamic_cast<Truck*>(vehicles[i]);
        if (truckPtr) {
            cout << "Successfully cast to Truck. Payload: " << truckPtr->getPayload() << " tons" << endl;
        }
    }

    cout << "\nDeleting Objects" << endl;
    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }

    return 0;
}

/*
 * EXPLANATION:
 * 
 * 1. dynamic_cast returns nullptr when the cast fails because the object 
 *    being pointed to is not an instance of the target derived class. 
 *    It performs a safe dynamic type check at runtime.
 * 
 * 2. If destructors were NOT virtual, deleting a derived class object through 
 *    a base class pointer (e.g., delete vehicles[1]) would only invoke the 
 *    Vehicle destructor. The Car/Truck destructor would never run, causing resource leak.
 */
