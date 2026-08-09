#include <iostream>

using namespace std;

class Distance {
private:
    int feet;
    float inches;

    // Helper function to normalize inches to feet
    void normalize() {
        if (inches >= 12.0) {
            int extraFeet = inches / 12;
            feet += extraFeet;
            inches -= extraFeet * 12;
        }
    }

public:
    Distance(int f = 0, float in = 0.0) {
        feet = f;
        inches = in;
        normalize();
    }

    // Unary negation operator (-)
    Distance operator-() const {
        return Distance(-feet, -inches);
    }

    // Prefix increment (++d)
    Distance operator++() {
        inches += 1.0;
        normalize();
        return *this;
    }

    // Postfix increment (d++)
    Distance operator++(int) {
        Distance temp = *this;
        inches += 1.0;
        normalize();
        return temp;
    }

    void display() const {
        cout << feet << " feet, " << inches << " inches" << endl;
    }

    // Friend functions for scalar multiplication
    friend Distance operator*(const Distance& d, int scalar);
    friend Distance operator*(int scalar, const Distance& d);
};

// Distance * int
Distance operator*(const Distance& d, int scalar) {
    int totalFeet = d.feet * scalar;
    float totalInches = d.inches * scalar;
    return Distance(totalFeet, totalInches); 
}

// int * Distance
Distance operator*(int scalar, const Distance& d) {
    return d * scalar; // reuse the previous operator implementation
}

int main() {
    Distance d1(5, 11.5);
    cout << "Original d1: ";
    d1.display();

    // Unary negation
    Distance d2 = -d1;
    cout << "Negated d1 (-d1): ";
    d2.display();

    // Prefix increment
    cout << "\nTesting prefix increment (++d1):\n";
    Distance d3 = ++d1;
    cout << "Returned value: "; d3.display();
    cout << "Actual d1: "; d1.display();

    // Postfix increment
    cout << "\nTesting postfix increment (d1++):\n";
    Distance d4 = d1++;
    cout << "Returned value: "; d4.display();
    cout << "Actual d1: "; d1.display();

    // Scalar multiplication
    cout << "\nTesting scalar multiplication:\n";
    Distance d5 = d1 * 2;
    cout << "d1 * 2 = "; d5.display();

    Distance d6 = 3 * d1;
    cout << "3 * d1 = "; d6.display();

    return 0;
}