#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() {
        cout << "Vehicle Destructor called" << endl;
    }
    virtual string getType() const {
        return "Vehicle";
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(int doors) : numDoors(doors) {}
    ~Car() override {
        cout << "Car Destructor called" << endl;
    }
    string getType() const override {
        return "Car";
    }
    int getDoors() const {
        return numDoors;
    }
};

class Truck : public Vehicle {
private:
    float payloadTons;
public:
    Truck(float payload) : payloadTons(payload) {}
    ~Truck() override {
        cout << "Truck Destructor called" << endl;
    }
    string getType() const override {
        return "Truck";
    }
    float getPayload() const {
        return payloadTons;
    }
};

int main() {
    Vehicle* vehicles[3];
    vehicles[0] = new Vehicle();
    vehicles[1] = new Car(4);
    vehicles[2] = new Truck(12.5f);

    for (int i = 0; i < 3; i++) {
        cout << "\n--- Vehicle " << i + 1 << " ---" << endl;
        cout << "Runtime type: " << typeid(*vehicles[i]).name() << endl;

        Car* carPtr = dynamic_cast<Car*>(vehicles[i]);
        if (carPtr) {
            cout << "Number of doors: " << carPtr->getDoors() << endl;
        }

        Truck* truckPtr = dynamic_cast<Truck*>(vehicles[i]);
        if (truckPtr) {
            cout << "Payload in tons: " << truckPtr->getPayload() << endl;
        }

        delete vehicles[i];
    }

    return 0;
}