/*
Question 5:
Write a program with a class Temperature having private member celsius.
Write a parameterized constructor.
Write const member functions toFahrenheit() and toKelvin().
Write a non-const function setTemp(float).
Write a friend function areEqual(Temperature t1, Temperature t2)
that returns true if both temperatures are the same.
*/

#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    Temperature(float c) {
        celsius = c;
    }

    void setTemp(float c) {
        celsius = c;
    }

    float toFahrenheit() const {
        return (celsius * 9 / 5) + 32;
    }

    float toKelvin() const {
        return celsius + 273.15;
    }

    void display() const {
        cout << "Celsius: " << celsius << endl;
        cout << "Fahrenheit: " << toFahrenheit() << endl;
        cout << "Kelvin: " << toKelvin() << endl;
    }

    friend bool areEqual(Temperature t1, Temperature t2);
};

bool areEqual(Temperature t1, Temperature t2) {
    return t1.celsius == t2.celsius;
}

int main() {
    Temperature t1(25);
    Temperature t2(25);

    cout << "Temperature 1:" << endl;
    t1.display();

    cout << "\nTemperature 2:" << endl;
    t2.display();

    if (areEqual(t1, t2)) {
        cout << "\nBoth temperatures are equal." << endl;
    } else {
        cout << "\nTemperatures are not equal." << endl;
    }

    t2.setTemp(30);

    cout << "\nAfter changing Temperature 2:" << endl;
    t2.display();

    return 0;
}