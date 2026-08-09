#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
    int marks;

public:
    Physics(int m = 0) {
        marks = m;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

class Maths {
private:
    int marks;

public:
    Maths(int m = 0) {
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
    int pMarks, mMarks;

    cout << "Enter Physics Marks: ";
    cin >> pMarks;

    cout << "Enter Maths Marks: ";
    cin >> mMarks;

    Physics p(pMarks);
    Maths m(mMarks);

    cout << "\nTotal Marks = "
         << totalMarks(p, m) << endl;

    if (isDistinction(p, m))
        cout << "Distinction Achieved\n";
    else
        cout << "No Distinction\n";

    return 0;
}
