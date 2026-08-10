#include <iostream>
using namespace std;

class Maths;

class Physics
{
private:
    int p;

public:
    Physics(int x)
    {
        p = x;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

class Maths
{
private:
    int m;

public:
    Maths(int x)
    {
        m = x;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

int totalMarks(Physics a, Maths b)
{
    return a.p + b.m;
}

bool isDistinction(Physics a, Maths b)
{
    return totalMarks(a, b) >= 160;
}

int main()
{
    int p, m;

    cout << "Enter Physics Mark: ";
    cin >> p;

    cout << "Enter Maths Mark: ";
    cin >> m;

    Physics a(p);
    Maths b(m);

    cout << "Total Marks: " << totalMarks(a, b) << endl;

    if (isDistinction(a, b))
        cout << "Distinction Achieved";
    else
        cout << "No Distinction";

    return 0;
}