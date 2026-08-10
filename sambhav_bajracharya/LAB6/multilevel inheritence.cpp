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

    void display() const {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string m, int y, int d) : Vehicle(m, y) {
        numDoors = d;
    }

    void display() const {
        Vehicle::display();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m, int y, int d, float b, int r) : Car(m, y, d) {
        batteryCapacity = b;
        range = r;
    }

    void display() const {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " miles" << endl;
    }
};

int main() {
    Vehicle v("Toyota", 2015);
    Car c("Honda", 2020, 4);
    ElectricCar ec("Tesla", 2023, 4, 75.5f, 330);

    cout << "Vehicle" << endl;
    v.display();

    cout << "\nCar" << endl;
    c.display();

    cout << "\nElectric Car" << endl;
    ec.display();

    return 0;
}
