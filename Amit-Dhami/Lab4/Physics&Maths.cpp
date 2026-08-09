#include<iostream>
using namespace std;
class Maths;
class Physics {
private:
    int mark;
public:
    Physics(int m) {
        mark = m;
    }
friend int totalMarks(Physics, Maths);
};
class Maths {
private:
    int mark;
public:
    Maths(int m) {
        mark = m;
    }
friend int totalMarks(Physics, Maths);
};
int totalMarks(Physics p, Maths m) {
    return p.mark + m.mark;
}

int main() {
    int pMark, mMark;
cout << "Enter Physics mark: ";
    cin >> pMark;
cout << "Enter Maths mark: ";
    cin >> mMark;
Physics p(pMark);
    Maths m(mMark);
int total = totalMarks(p, m);
cout << "Total Marks = " << total << endl;
if (total >= 160)
        cout << "Distinction Achieved";
    else
        cout << "Distinction Not Achieved";

    return 0;
}
