#include <iostream>

using namespace std;

// Forward declaration needed so Celsius can reference Fahrenheit
class Fahrenheit;

class Celsius {
private:
    float temp;

public:
    // Default constructor
    Celsius() : temp(0.0) {}

    // Converting constructor from float
    Celsius(float t) {
        temp = t;
    }

    // Conversion operator to float
    operator float() const {
        return temp;
    }

    // Conversion operator to Fahrenheit inline declaration
    operator Fahrenheit() const;

    friend ostream& operator<<(ostream& out, const Celsius& c);
};

class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit() : temp(32.0) {}
    
    Fahrenheit(float t) {
        temp = t;
    }

    // Converting constructor from Celsius
    Fahrenheit(const Celsius& c) {
        // Explicitly using float conversion operator from Celsius class
        float c_val = (float)c; 
        temp = c_val * 9.0 / 5.0 + 32.0;
    }

    friend ostream& operator<<(ostream& out, const Fahrenheit& f);
};

// Definition of Celsius conversion to Fahrenheit
Celsius::operator Fahrenheit() const {
    return Fahrenheit(temp * 9.0 / 5.0 + 32.0);
}

// Stream operators implementation
ostream& operator<<(ostream& out, const Celsius& c) {
    out << c.temp << " C";
    return out;
}

ostream& operator<<(ostream& out, const Fahrenheit& f) {
    out << f.temp << " F";
    return out;
}

int main() {
    // 1. Assigning a float directly to a Celsius object
    Celsius c1 = 25.5f; 
    cout << "Assigned float to Celsius: " << c1 << endl;

    // 2. Extracting a float from a Celsius object
    float extractedFloat = (float)c1; 
    cout << "Extracted float value: " << extractedFloat << endl;

    // 3. Converting from Celsius to Fahrenheit (via operator Fahrenheit)
    Fahrenheit f1 = c1; 
    cout << "Converted Celsius to Fahrenheit: " << f1 << endl;

    // 4. Converting from Fahrenheit via converting constructor
    Celsius c2(100.0f);
    Fahrenheit f2(c2); 
    cout << "100 C converted to Fahrenheit: " << f2 << endl;

    return 0;
}
