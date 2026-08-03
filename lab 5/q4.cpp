#include<iostream>
using namespace std;

class Maths;

class Physics
{
private:
    int mark;

public:
    void input()
    {
        cout<<"Enter Physics Marks: ";
        cin>>mark;
    }

    friend int totalMarks(Physics,Maths);
    friend bool isDistinction(Physics,Maths);
};

class Maths
{
private:
    int mark;

public:
    void input()
    {
        cout<<"Enter Maths Marks: ";
        cin>>mark;
    }

    friend int totalMarks(Physics,Maths);
    friend bool isDistinction(Physics,Maths);
};

int totalMarks(Physics p,Maths m)
{
    return p.mark+m.mark;
}

bool isDistinction(Physics p,Maths m)
{
    return totalMarks(p,m)>=160;
}

int main()
{
    Physics p;
    Maths m;

    p.input();
    m.input();

    cout<<"Total Marks = "<<totalMarks(p,m)<<endl;

    if(isDistinction(p,m))
        cout<<"Distinction Achieved";
    else
        cout<<"No Distinction";

    return 0;
}