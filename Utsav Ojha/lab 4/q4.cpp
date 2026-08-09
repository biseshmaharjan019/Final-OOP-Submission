#include <iostream>
using namespace std;

class Maths;

class Physics
{
private:
    int mark;

public:
    Physics(int m)
    {
        mark = m;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

class Maths
{
private:
    int mark;

public:
    Maths(int m)
    {
        mark = m;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

int totalMarks(Physics p, Maths m)
{
    return p.mark + m.mark;
}

bool isDistinction(Physics p, Maths m)
{
    return totalMarks(p, m) >= 160;
}

int main()
{
    int p, m;

    cout << "Enter Physics Marks: ";
    cin >> p;

    cout << "Enter Maths Marks: ";
    cin >> m;

    Physics P(p);
    Maths M(m);

    cout << "Total Marks = "
         << totalMarks(P, M) << endl;

    if (isDistinction(P, M))
        cout << "Distinction Achieved";
    else
        cout << "No Distinction";

    return 0;
}
