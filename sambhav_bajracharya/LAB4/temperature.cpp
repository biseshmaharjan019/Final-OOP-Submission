#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    Temperature(float c = 0.0f) {
        celsius = c;
    }

    float toFahrenheit() const {
        return (celsius * 9.0f / 5.0f) + 32.0f;
    }

    float toKelvin() const {
        return celsius + 273.15f;
    }

    void setTemp(float c) {
        celsius = c;
    }

    friend bool areEqual(Temperature t1, Temperature t2);
};

bool areEqual(Temperature t1, Temperature t2) {
    return t1.celsius == t2.celsius;
}

int main() {
    Temperature t1(25.0f);
    Temperature t2(25.0f);
    Temperature t3(100.0f);

    cout << "Temperature 1:" << endl;
    cout << "Fahrenheit: " << t1.toFahrenheit() << " F" << endl;
    cout << "Kelvin: " << t1.toKelvin() << " K" << endl;

    cout << "\nComparing t1 and t2: ";
    if (areEqual(t1, t2)) {
        cout << "Temperatures are equal." << endl;
    } else {
        cout << "Temperatures are different." << endl;
    }

    cout << "Comparing t1 and t3: ";
    if (areEqual(t1, t3)) {
        cout << "Temperatures are equal." << endl;
    } else {
        cout << "Temperatures are different." << endl;
    }

    return 0;
}
