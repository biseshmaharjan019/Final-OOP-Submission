#include <iostream>
using namespace std;

class Temperature {
private:
    float c;

public:
    Temperature(float x) {
        c = x;
    }

    void setTemp(float x) {
        c = x;
    }

    float toFahrenheit() const {
        return (c * 9 / 5) + 32;
    }

    float toKelvin() const {
        return c + 273.15;
    }

    friend bool areEqual(Temperature, Temperature);
};

bool areEqual(Temperature a, Temperature b) {
    return a.c == b.c;
}

int main() {
    Temperature t1(25);
    Temperature t2(25);

    cout << "Fahrenheit: " << t1.toFahrenheit() << endl;
    cout << "Kelvin: " << t1.toKelvin() << endl;

    if (areEqual(t1, t2))
        cout << "Equal";
    else
        cout << "Not Equal";

    return 0;
}