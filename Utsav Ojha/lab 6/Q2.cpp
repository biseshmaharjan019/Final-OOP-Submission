#include<iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance(int f = 0, float i = 0.0) {
        feet = f;
        inches = i;
    }

    Distance operator-() {
        return Distance(-feet, -inches);
    }

    Distance operator++() {
        inches++;
        if(inches >= 12) {
            feet++;
            inches -= 12;
        }
        return *this;
    }

    Distance operator++(int) {
        Distance temp = *this;
        inches++;
        if(inches >= 12) {
            feet++;
            inches -= 12;
        }
        return temp;
    }

  
    friend Distance operator*(Distance d, int n);
    friend Distance operator*(int n, Distance d);

    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

Distance operator*(Distance d, int n) {
    float totalInches = (d.feet * 12 + d.inches) * n;
    int f = (int)totalInches / 12;
    float i = totalInches - f * 12;
    return Distance(f, i);
}

Distance operator*(int n, Distance d) {
    return d * n;
}

int main() {
    Distance d1(3, 10.5);

    cout << "Original: ";
    d1.display();

    Distance d2 = -d1;
    cout << "Negated: ";
    d2.display();

    cout << "After prefix ++: ";
    ++d1;
    d1.display();

    cout << "Postfix ++ (returns old): ";
    Distance d3 = d1++;
    d3.display();

    cout << "d1 after postfix++: ";
    d1.display();

    cout << "d1 * 3: ";
    Distance d4 = d1 * 3;
    d4.display();

    cout << "2 * d1: ";
    Distance d5 = 2 * d1;
    d5.display();

    return 0;
}