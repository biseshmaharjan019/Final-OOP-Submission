#include <iostream>
#include <typeinfo>    
using namespace std;

class Vehicle {
public:
    virtual string getType() const { return "Vehicle"; }

    
    
    virtual ~Vehicle() {
        cout << "[~Vehicle destructor called]" << endl;
    }
};

class Car : public Vehicle {
    int numDoors;
public:
    Car(int doors) : numDoors(doors) {}

    string getType() const override { return "Car"; }

    int getDoors() const { return numDoors; }

    virtual ~Car() {
        cout << "[~Car destructor called]" << endl;
    }
};

class Truck : public Vehicle {
    float payloadTons;
public:
    Truck(float payload) : payloadTons(payload) {}

    string getType() const override { return "Truck"; }

    float getPayload() const { return payloadTons; }

    virtual ~Truck() {
        cout << "[~Truck destructor called]" << endl;
    }
};

int main() {
    
    Vehicle* fleet[3] = {
        new Vehicle(),
        new Car(4),
        new Truck(12.5f)
    };

    cout << "============================================" << endl;
    cout << "  RTTI Demo: typeid  +  dynamic_cast"        << endl;
    cout << "============================================" << endl;

    for (int i = 0; i < 3; ++i) {
        Vehicle* ptr = fleet[i];

        cout << "\n--- Object [" << i << "] ---" << endl;

        
        
        cout << "typeid name : " << typeid(*ptr).name() << endl;
        cout << "getType()   : " << ptr->getType()      << endl;

        

        
        Car* carPtr = dynamic_cast<Car*>(ptr);
        if (carPtr != nullptr) {
            cout << "Cast to Car* succeeded. Doors = "
                 << carPtr->getDoors() << endl;
        } else {
            cout << "Cast to Car*   -> nullptr (not a Car)"  << endl;
        }

        Truck* truckPtr = dynamic_cast<Truck*>(ptr);
        if (truckPtr != nullptr) {
            cout << "Cast to Truck* succeeded. Payload = "
                 << truckPtr->getPayload() << " tons" << endl;
        } else {
            cout << "Cast to Truck* -> nullptr (not a Truck)" << endl;
        }

        cout << "Deleting object..." << endl;
        delete ptr;
    }

    cout << "\n============================================" << endl;

    

    

    

    

    

    

    

    return 0;
}