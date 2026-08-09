#include <iostream>
#include <string>

class Vehicle {
private:
    std::string make;
    int year;

public:
    Vehicle(std::string m, int y) : make(m), year(y) {}

    void display() const {
        std::cout << "Make: " << make << "\nYear: " << year << std::endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(std::string m, int y, int d) 
        : Vehicle(m, y), numDoors(d) {}

    void display() const {
        Vehicle::display();
        std::cout << "Number of Doors: " << numDoors << std::endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(std::string m, int y, int d, float cap, int r) 
        : Car(m, y, d), batteryCapacity(cap), range(r) {}

    void display() const {
        Car::display();
        std::cout << "Battery Capacity: " << batteryCapacity << " kWh"
                  << "\nRange: " << range << " miles" << std::endl;
    }
};

int main() {
    std::cout << "=== Vehicle Object ===" << std::endl;
    Vehicle v("Ford", 2018);
    v.display();

    std::cout << "\n=== Car Object ===" << std::endl;
    Car c("Toyota", 2021, 4);
    c.display();

    std::cout << "\n=== ElectricCar Object ===" << std::endl;
    ElectricCar ec("Tesla", 2024, 4, 82.5f, 330);
    ec.display();

    return 0;
}