#include <iostream>
using namespace std;

class P {
private:
    string n;
    int a;

public:
    P(string name, int age) : n(name), a(age) {}
    string getN() const { return n; }
    int getA() const { return a; }
    void show() const { cout << "Name: " << n << "\nAge: " << a << endl; }
};

class S : public P {
private:
    int r;
    float g;

public:
    S(string name, int age, int roll, float gpa) : P(name, age), r(roll), g(gpa) {}
    void show() const {
        cout << "Name: " << getN() << "\nAge: " << getA()
             << "\nRoll: " << r << "\nGPA: " << g << endl;
    }
};

int main() {
    P p("A", 1);
    S s("A", 1, 2, 3.2);

    cout << "Person:\n"; p.show();
    cout << "\nStudent:\n"; s.show();

    return 0;
}
