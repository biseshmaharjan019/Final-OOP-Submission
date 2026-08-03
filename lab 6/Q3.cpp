#include <iostream>
using namespace std;

class Fahrenheit; 
class Celsius {
private:
    float temp;
public:
    Celsius(float t = 0) : temp(t) {}

    float getTemp() const { return temp; }

    
    operator Fahrenheit();
};

class Fahrenheit {
private:
    float temp;
public:
    Fahrenheit(float t = 0) : temp(t) {}

   

    float getTemp() const { return temp; }

    friend ostream& operator<<(ostream& out, const Fahrenheit& f) {
        out << f.temp << "°F";
        return out;
    }
};


Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9.0 / 5.0) + 32);
}

int main() {
    Celsius c1(0), c2(100), c3(37);

    Fahrenheit f1 = c1;  
    Fahrenheit f2 = c2;
    Fahrenheit f3 = c3;

    cout << "0°C   = " << f1 << endl;
    cout << "100°C = " << f2 << endl;
    cout << "37°C  = " << f3 << endl;

    return 0;
}