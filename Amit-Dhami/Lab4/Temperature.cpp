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
void setTemp(float t) {
        celsius = t;
    }
friend void areEqual(Temperature, Temperature);
};

void areEqual(Temperature t1, Temperature t2) {
    if (t1.celsius == t2.celsius)
        cout << "Temperatures are equal" << endl;
    else
        cout << "Temperatures are not equal" << endl;
}

int main() {
    Temperature t1(25);
    Temperature t2(25);
cout << "Fahrenheit: " << t1.toFahrenheit() << endl;
    cout << "Kelvin: " << t1.toKelvin() << endl;
areEqual(t1, t2);
t2.setTemp(30);
areEqual(t1, t2);

    return 0;
}
