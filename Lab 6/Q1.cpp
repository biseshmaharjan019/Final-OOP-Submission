// Person and Student Class Hierarchy with Virtual Functions

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Person
{
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void display() const
    {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }
};

class Student : public Person
{
    int rollNo;
    float gpa;

public:
    Student(string n, int a, int r, float g) : Person(n, a), rollNo(r), gpa(g) {}

    void display() const override
    {
        cout << "Name: " << getName() << "\nAge: " << getAge() << "\nRoll No: " << rollNo << "\nGPA: " << gpa << endl;
    }
};

int main()
{
    Person p("Ram", 25);
    Student s("Shyam", 20, 101, 3.75);

    cout << "Person:" << endl;
    p.display();

    cout << "\nStudent:" << endl;
    s.display();

    system("pause");
    return 0;
}