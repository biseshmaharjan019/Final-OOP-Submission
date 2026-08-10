#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string make;
    int year;
public:
    Vehicle(string m, int y) {
        make = m;
        year = y;
    }
    void display() {
        cout << "Make: " << make << ", Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(string m, int y, int d) : Vehicle(m, y) {
        numDoors = d;
    }
    void display() {
        Vehicle::display();
        cout << "Doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryCapacity;
    int range;
public:
    ElectricCar(string m, int y, int d, float cap, int r) : Car(m, y, d) {
        batteryCapacity = cap;
        range = r;
    }
    void display() {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh, Range: " << range << " miles" << endl;
    }
};

int main() {
    cout << "--- Vehicle ---" << endl;
    Vehicle v("Toyota", 2015);
    v.display();

    cout << "\n--- Car ---" << endl;
    Car c("Honda", 2020, 4);
    c.display();

    cout << "\n--- Electric Car ---" << endl;
    ElectricCar ec("Tesla", 2023, 4, 75.5f, 300);
    ec.display();

    return 0;
}
