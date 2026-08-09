#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }
    virtual string getType() {
        return "Vehicle";
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(int doors) { numDoors = doors; }
    ~Car() override {
        cout << "Car destructor called" << endl;
    }
    void getDoors() {
        cout << "Number of doors: " << numDoors << endl;
    }
};

class Truck : public Vehicle {
private:
    float payloadTons;
public:
    Truck(float payload) { payloadTons = payload; }
    ~Truck() override {
        cout << "Truck destructor called" << endl;
    }
    void getPayload() {
        cout << "Payload tons: " << payloadTons << endl;
    }
};

int main() {
    Vehicle* list[3];
    list[0] = new Vehicle();
    list[1] = new Car(4);
    list[2] = new Truck(5.5f);
    
    for (int i = 0; i < 3; i++) {
        cout << "\nProcessing item " << i << ":" << endl;
        cout << "Runtime type: " << typeid(*list[i]).name() << endl;
        
        Car* carPtr = dynamic_cast<Car*>(list[i]);
        if (carPtr != nullptr) {
            carPtr->getDoors();
        }
        
        Truck* truckPtr = dynamic_cast<Truck*>(list[i]);
        if (truckPtr != nullptr) {
            truckPtr->getPayload();
        }
        
        delete list[i];
    }
    
    return 0;
}