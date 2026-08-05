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
    Distance(int f = 0, float i = 0.0f) {
        feet = f;
        inches = i;
        normalize();
    }

    void display() const {
        cout << feet << " ft " << inches << " in";
    }

    Distance operator++() {
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

    friend Distance operator-(const Distance& d);
    friend Distance operator*(const Distance& d, int scalar);
    friend Distance operator*(int scalar, const Distance& d);
};

Distance operator-(const Distance& d) {
    return Distance(-d.feet, -d.inches);
}

Distance operator*(const Distance& d, int scalar) {
    return Distance(d.feet * scalar, d.inches * scalar);
}

Distance operator*(int scalar, const Distance& d) {
    return d * scalar;
}

int main() {
    Distance d1(5, 10.5f);

    cout << "Original Distance d1: ";
    d1.display();
    cout << endl;

    Distance d2 = -d1;
    cout << "Negated Distance (-d1): ";
    d2.display();
    cout << endl;

    cout << "Prefix Increment (++d1): ";
    (++d1).display();
    cout << endl;

    cout << "Postfix Increment (d1++): ";
    (d1++).display();
    cout << "\nValue after Postfix Increment: ";
    d1.display();
    cout << endl;

    Distance d3 = d1 * 3;
    cout << "d1 * 3: ";
    d3.display();
    cout << endl;

    Distance d4 = 2 * d1;
    cout << "2 * d1: ";
    d4.display();
    cout << endl;

    return 0;
}
