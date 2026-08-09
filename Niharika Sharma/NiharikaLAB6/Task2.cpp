#include<iostream>
using namespace std;

// Base Class
class Vehicle {
private:
    string make;
    int year;

public:
    Vehicle(string m, int y) {
        make = m;
        year = y;
    }

    string getMake() {
        return make;
    }

    int getYear() {
        return year;
    }

    void display() {
        cout << "Make : " << make << endl;
        cout << "Year : " << year << endl;
    }
};

// Derived Class
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string m, int y, int d) : Vehicle(m, y) {
        numDoors = d;
    }

    void display() {
        cout << "Make      : " << getMake() << endl;
        cout << "Year      : " << getYear() << endl;
        cout << "No. Doors : " << numDoors << endl;
    }

    int getDoors() {
        return numDoors;
    }
};

// Derived Class
class ElectricCar : public Car {
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m, int y, int d, float b, int r)
        : Car(m, y, d) {
        batteryCapacity = b;
        range = r;
    }

    void display() {
        cout << "Make             : " << getMake() << endl;
        cout << "Year             : " << getYear() << endl;
        cout << "No. Doors        : " << getDoors() << endl;
        cout << "Battery Capacity : " << batteryCapacity << " kWh" << endl;
        cout << "Range            : " << range << " km" << endl;
    }
};

int main() {
    Vehicle v("BMW", 2020);
    Car c("Rolls Royce", 2022, 4);
    ElectricCar e("Tesla", 2024, 4, 75.5, 500);

    cout << "Vehicle Details:\n";
    v.display();

    cout << "\nCar Details:\n";
    c.display();

    cout << "\nElectric Car Details:\n";
    e.display();

    return 0;
}
