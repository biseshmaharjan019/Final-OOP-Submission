#include <iostream>
using namespace std;
class Fahrenheit;
class Celsius {
private:
    float temp;
public:
    Celsius(float t = 0) {
        temp = t;
    }
    operator float() const {
        return temp;
    }
    operator Fahrenheit();
    friend ostream& operator<<(ostream& out, const Celsius& c);
};

class Fahrenheit {
private:
    float temp;
public:
    Fahrenheit(float t = 0) {
        temp = t;
    }
    Fahrenheit(const Celsius& c);

    friend ostream& operator<<(ostream& out, const Fahrenheit& f);
};
Fahrenheit::Fahrenheit(const Celsius& c) {
    temp = (float)c * 9 / 5 + 32;
}
Celsius::operator Fahrenheit() {
    return Fahrenheit(temp * 9 / 5 + 32);
}
ostream& operator<<(ostream& out, const Celsius& c) {
    out << c.temp << " °C";
    return out;
}
ostream& operator<<(ostream& out, const Fahrenheit& f) {
    out << f.temp << " °F";
    return out;
}
int main() {
    Celsius c = 25.5;
    float value = c;
    Fahrenheit f1 = c;
    Fahrenheit f2(c);
    cout << "Celsius object: " << c << endl;
    cout << "Float value extracted from Celsius: " << value << endl;
    cout << "Fahrenheit (using conversion operator): " << f1 << endl;
    cout << "Fahrenheit (using constructor): " << f2 << endl;
    return 0;
}
