#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    Temperature(float c = 0) {
        celsius = c;
    }

    float toFahrenheit() const {
        return (celsius * 9 / 5) + 32;
    }

    float toKelvin() const {
        return celsius + 273.15;
    }

    void setTemp(float c) {
        celsius = c;
    }

    friend bool areEqual(Temperature, Temperature);

    void display() const {
        cout << "Celsius    : " << celsius << endl;
        cout << "Fahrenheit : "
             << toFahrenheit() << endl;
        cout << "Kelvin     : "
             << toKelvin() << endl;
    }
};

bool areEqual(Temperature t1, Temperature t2) {
    return t1.celsius == t2.celsius;
}

int main() {
    Temperature t1(25);
    Temperature t2(25);

    t1.display();

    cout << endl;

    t2.display();

    if (areEqual(t1, t2))
        cout << "\nTemperatures are Equal\n";
    else
        cout << "\nTemperatures are Not Equal\n";

    return 0;
}
