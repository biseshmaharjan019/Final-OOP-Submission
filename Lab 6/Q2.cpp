// Vehicle, Car, and ElectricCar Multilevel Inheritance Hierarchy

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Vehicle
{
    string make;
    int year;

public:
    Vehicle(string m, int y) : make(m), year(y) {}

    void display() const
    {
        cout << "Make: " << make << "\nYear: " << year << endl;
    }
};

class Car : public Vehicle
{
    int numDoors;

public:
    Car(string m, int y, int d) : Vehicle(m, y), numDoors(d) {}

    void display() const
    {
        Vehicle::display();
        cout << "Number of doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car
{
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m, int y, int d, float b, int r)
        : Car(m, y, d), batteryCapacity(b), range(r) {}

    void display() const
    {
        Car::display();
        cout << "Battery capacity: " << batteryCapacity << " kWh\nRange: " << range << " km" << endl;
    }
};

int main()
{
    Vehicle v("Toyota", 2020);
    Car c("Honda", 2022, 4);
    ElectricCar e("Tesla", 2025, 4, 75.5, 480);

    cout << "Vehicle:" << endl;
    v.display();

    cout << "\nCar:" << endl;
    c.display();

    cout << "\nElectric Car:" << endl;
    e.display();

    system("pause");
    return 0;
}