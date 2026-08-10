#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
    float mark;

public:
    Physics(float m = 0.0) {
        mark = m;
    }

    friend float totalMarks(const Physics& p, const Maths& m);
    friend bool isDistinction(const Physics& p, const Maths& m);
};

class Maths {
private:
    float mark;

public:
    Maths(float m = 0.0) {
        mark = m;
    }

    friend float totalMarks(const Physics& p, const Maths& m);
    friend bool isDistinction(const Physics& p, const Maths& m);
};

float totalMarks(const Physics& p, const Maths& m) {
    return p.mark + m.mark;
}

bool isDistinction(const Physics& p, const Maths& m) {
    return totalMarks(p, m) >= 160.0f;
}

int main() {
    float phyMarks, mathMarks;

    cout << "Enter Physics marks (out of 100): ";
    cin >> phyMarks;
    cout << "Enter Maths marks (out of 100): ";
    cin >> mathMarks;

    Physics p(phyMarks);
    Maths m(mathMarks);

    float total = totalMarks(p, m);
    cout << "\nTotal Combined Marks: " << total << " / 200" << endl;

    if (isDistinction(p, m)) {
        cout << "Status: Distinction achieved!" << endl;
    } else {
        cout << "Status: Distinction not achieved." << endl;
    }

    return 0;
}
