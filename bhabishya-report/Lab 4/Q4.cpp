#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
    int marks;

public:
    Physics(int m) {
        marks = m;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

class Maths {
private:
    int marks;

public:
    Maths(int m) {
        marks = m;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

int totalMarks(Physics p, Maths m) {
    return p.marks + m.marks;
}

bool isDistinction(Physics p, Maths m) {
    return totalMarks(p, m) >= 160;
}

int main() {
    int physicsMarks, mathsMarks;

    cout << "Enter Physics marks: ";
    cin >> physicsMarks;

    cout << "Enter Maths marks: ";
    cin >> mathsMarks;

    Physics p(physicsMarks);
    Maths m(mathsMarks);

    cout << "\nTotal marks: " << totalMarks(p, m) << endl;

    if (isDistinction(p, m))
        cout << "Distinction achieved." << endl;
    else
        cout << "Distinction not achieved." << endl;

    system("pause");
    return 0;
}
