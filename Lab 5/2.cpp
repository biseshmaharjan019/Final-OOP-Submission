#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

    void normalize() {
        while (inches >= 12.0f) {
            inches -= 12.0f;
            feet++;
        }
        while (inches < 0.0f && feet > 0) {
            inches += 12.0f;
            feet--;
        }
    }

public:
    Distance(int f = 0, float i = 0.0f) : feet(f), inches(i) {
        normalize();
    }

    Distance operator-() const {
        return Distance(-feet, -inches);
    }
    Distance& operator++() {
        inches += 1.0f;
        normalize();
        return *this;
    }
    Distance operator++(int) {
        Distance temp = *this;
        inches += 1.0f;
        normalize();
        return temp;
    }
    friend Distance operator*(const Distance& d, int scalar) {
        return Distance(d.feet * scalar, d.inches * scalar);
    }

    friend Distance operator*(int scalar, const Distance& d) {
        return Distance(d.feet * scalar, d.inches * scalar);
    }

    void display() const {
        cout << feet << " ft " << inches << " in";
    }
};

int main() {
    Distance d1(5, 11.5f);
    cout << "Original Distance d1: ";
    d1.display();
    cout << endl;
    Distance d2 = -d1;
    cout << "Negated Distance (-d1): ";
    d2.display();
    cout << endl;
    cout << "\nPrefix ++d1: ";
    (++d1).display();
    cout << endl;
    cout << "Postfix d1++: ";
    (d1++).display();
    cout << "\nAfter Postfix d1: ";
    d1.display();
    cout << endl;
    Distance d3 = d1 * 2;
    Distance d4 = 3 * d1;

    cout << "\nd1 * 2: ";
    d3.display();
    cout << "\n3 * d1: ";
    d4.display();
    cout << endl;

    return 0;
}