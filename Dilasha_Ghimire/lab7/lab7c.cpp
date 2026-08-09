#include <iostream>
#include <string>
#include <typeinfo>

class Vehicle {
public:
    virtual std::string getType() const {
        return "Vehicle";
    }

    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called" << std::endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(int doors) : numDoors(doors) {}

    int getDoors() const {
        return numDoors;
    }

    std::string getType() const override {
        return "Car";
    }

    ~Car() override {
        std::cout << "Car destructor called" << std::endl;
    }
};

class Truck : public Vehicle {
private:
    float payloadTons;

public:
    Truck(float payload) : payloadTons(payload) {}

    float getPayload() const {
        return payloadTons;
    }

    std::string getType() const override {
        return "Truck";
    }

    ~Truck() override {
        std::cout << "Truck destructor called" << std::endl;
    }
};

int main() {
    Vehicle* vehicles[3];
    vehicles[0] = new Vehicle();
    vehicles[1] = new Car(4);
    vehicles[2] = new Truck(15.5f);

    for (int i = 0; i < 3; ++i) {
        std::cout << "------------------------------" << std::endl;
        std::cout << "Runtime Type: " << typeid(*vehicles[i]).name() << std::endl;

        Car* carPtr = dynamic_cast<Car*>(vehicles[i]);
        if (carPtr != nullptr) {
            std::cout << "Doors: " << carPtr->getDoors() << std::endl;
        }

        Truck* truckPtr = dynamic_cast<Truck*>(vehicles[i]);
        if (truckPtr != nullptr) {
            std::cout << "Payload: " << truckPtr->getPayload() << " tons" << std::endl;
        }

        delete vehicles[i];
    }

    return 0;
}

