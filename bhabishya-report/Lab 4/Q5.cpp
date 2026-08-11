#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    Temperature(float c) {
        celsius = c;
    }

    float toFahrenheit() const {
        return (celsius * 9 / 5) + 32;
    }

    float toKelvin() const {
        return celsius + 273.15;
    }

    void setTemp(float temp) {
        celsius = temp;
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
    cout << "Fahrenheit: " << t1.toFahrenheit() << endl;
    cout << "Kelvin: " << t1.toKelvin() << endl;

    t1.setTemp(30);

    cout << "\nAfter changing Temperature 1:" << endl;
    cout << "Fahrenheit: " << t1.toFahrenheit() << endl;
    cout << "Kelvin: " << t1.toKelvin() << endl;

    if (areEqual(t1, t2))
        cout << "\nBoth temperatures are equal." << endl;
    else
        cout << "\nBoth temperatures are not equal." << endl;

    system("pause");
    return 0;
}
