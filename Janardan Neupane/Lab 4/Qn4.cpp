/*
Question 4:
Write a program with two classes Physics and Maths, each having private mark data members.
Write a friend function totalMarks() that is friend of both classes and returns the sum of all marks.
Write a second friend function isDistinction() that returns true if totalMarks >= 160 out of 200.
Read marks for both subjects in main and display the total and distinction status.
*/

#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
    float marks;

public:
    Physics(float m) {
        marks = m;
    }

    friend float totalMarks(Physics p, Maths m);
    friend bool isDistinction(Physics p, Maths m);
};

class Maths {
private:
    float marks;

public:
    Maths(float m) {
        marks = m;
    }

    friend float totalMarks(Physics p, Maths m);
    friend bool isDistinction(Physics p, Maths m);
};

float totalMarks(Physics p, Maths m) {
    return p.marks + m.marks;
}

bool isDistinction(Physics p, Maths m) {
    return totalMarks(p, m) >= 160;
}

int main() {
    float phy, math;

    cout << "Enter Physics marks: ";
    cin >> phy;

    cout << "Enter Maths marks: ";
    cin >> math;

    Physics p(phy);
    Maths m(math);

    cout << "Total Marks: " << totalMarks(p, m) << "/200" << endl;

    if (isDistinction(p, m)) {
        cout << "Distinction Achieved" << endl;
    } else {
        cout << "Distinction Not Achieved" << endl;
    }

    return 0;
}