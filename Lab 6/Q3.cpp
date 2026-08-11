// Teacher, Researcher, and Professor Multiple Inheritance

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Teacher
{
    int teacherID;
    string subject;

public:
    Teacher(int i, string s) : teacherID(i), subject(s) {}

    void display() const
    {
        cout << "Teacher ID: " << teacherID << "\nSubject: " << subject << endl;
    }
};

class Researcher
{
    string researchArea;
    int publications;

public:
    Researcher(string r, int p) : researchArea(r), publications(p) {}

    void display() const
    {
        cout << "Research Area: " << researchArea << "\nPublications: " << publications << endl;
    }
};

class Professor : public Teacher, public Researcher
{
    string university;

public:
    Professor(int i, string s, string r, int p, string u)
        : Teacher(i, s), Researcher(r, p), university(u) {}

    void display() const
    {
        Teacher::display();
        Researcher::display();
        cout << "University: " << university << endl;
    }
};

int main()
{
    Professor p(101, "Physics", "Quantum Physics", 12, "ABC University");
    p.display();

    system("pause");
    return 0;
}