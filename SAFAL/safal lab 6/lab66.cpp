#include <iostream>
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

protected:
    string getMake() {
        return make;
    }

    int getYear() {
        return year;
    }
public:
    void display() {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    }
};
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string m, int y, int d)
        : Vehicle(m, y) {
        numDoors = d;
    }
protected:
    int getDoors() {
        return numDoors;
    }
public:
    void display() {
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Doors: " << numDoors << endl;
    }
};
class ElectricCar : public Car {
private:
    float batteryCapacity;
    int rangeValue;
public:
    ElectricCar(string m, int y, int d, float b, int r)
        : Car(m, y, d) {
        batteryCapacity = b;
        rangeValue = r;
    }
    void display() {
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Doors: " << getDoors() << endl;
        cout << "Battery Capacity: " << batteryCapacity << endl;
        cout << "Range: " << rangeValue << endl;
    }
};
int main() {
    Vehicle v("Toyota", 2020);
    Car c("Honda", 2022, 4);
    ElectricCar e("Tesla", 2025, 4, 75.5, 500);
    v.display();
    cout << endl;
    c.display();
    cout << endl;
    e.display();
    return 0;
}
