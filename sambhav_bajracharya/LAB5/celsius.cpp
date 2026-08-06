#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    float temperature;

public:
    Celsius(float temp = 0.0f) {
        temperature = temp;
    }

    operator float() const {
        return temperature;
    }

    operator Fahrenheit() const;

    friend ostream& operator<<(ostream& out, const Celsius& c);
};

class Fahrenheit {
private:
    float temperature;

public:
    Fahrenheit(float temp = 0.0f) {
        temperature = temp;
    }

    Fahrenheit(const Celsius& c) {
        temperature = ((float)c * 9.0f / 5.0f) + 32.0f;
    }

    friend ostream& operator<<(ostream& out, const Fahrenheit& f);
};

Celsius::operator Fahrenheit() const {
    return Fahrenheit((temperature * 9.0f / 5.0f) + 32.0f);
}

ostream& operator<<(ostream& out, const Celsius& c) {
    out << c.temperature << " C";
    return out;
}

ostream& operator<<(ostream& out, const Fahrenheit& f) {
    out << f.temperature << " F";
    return out;
}

int main() {
    Celsius c1 = 37.0f;
    cout << "Assigned float to Celsius object: " << c1 << endl;

    float rawValue = c1;
    cout << "Extracted float value from Celsius object: " << rawValue << endl;

    Fahrenheit f1 = c1;
    cout << "Converted Celsius object to Fahrenheit object: " << f1 << endl;

    Fahrenheit f2(100.0f);
    cout << "Direct Fahrenheit object: " << f2 << endl;

    return 0;
}
