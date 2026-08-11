#include <iostream>
using namespace std;

class Fahrenheit;
class Celsius {
private:
    float temp;

public:
    Celsius(float t = 0.0f) : temp(t) {}
    operator float() const {
        return temp;
    }
    operator Fahrenheit() const;

    float getTemp() const { return temp; }

    friend ostream& operator<<(ostream& os, const Celsius& c) {
        os << c.temp << " °C";
        return os;
    }
};

class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit(float t = 0.0f) : temp(t) {}
    Fahrenheit(const Celsius& c) {
        temp = c.getTemp() * 9.0f / 5.0f + 32.0f;
    }

    float getTemp() const { return temp; }

    friend ostream& operator<<(ostream& os, const Fahrenheit& f) {
        os << f.temp << " °F";
        return os;
    }
};
Celsius::operator Fahrenheit() const {
    return Fahrenheit(temp * 9.0f / 5.0f + 32.0f);
}

int main() {    Celsius c1 = 37.0f; 
    cout << "Celsius object c1: " << c1 << endl;
    float rawTemp = float(c1);
    cout << "Extracted float value from c1: " << rawTemp << endl;
    Fahrenheit f1 = c1;
    cout << "Converted to Fahrenheit (f1): " << f1 << endl;
    Celsius c2(100.0f);
    Fahrenheit f2(c2);
    cout << "Celsius c2: " << c2 << " converted to Fahrenheit f2: " << f2 << endl;

    return 0;
}