#include <iostream>
using namespace std;

class Employee
{
public:
    virtual float calculateSalary() = 0;
    virtual void display() = 0;
};

class FullTimeEmployee : public Employee
{
    float salary;

public:
    FullTimeEmployee(float s)
    {
        salary = s;
    }

    float calculateSalary()
    {
        return salary;
    }

    void display()
    {
        cout << "Full Time Salary: " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee
{
    int hours;
    float rate;

public:
    PartTimeEmployee(int h, float r)
    {
        hours = h;
        rate = r;
    }

    float calculateSalary()
    {
        return hours * rate;
    }

    void display()
    {
        cout << "Part Time Salary: " << calculateSalary() << endl;
    }
};

class Contractor : public Employee
{
    float projectFee;
    float taxRate;

public:
    Contractor(float p, float t)
    {
        projectFee = p;
        taxRate = t;
    }

    float calculateSalary()
    {
        return projectFee - (projectFee * taxRate / 100);
    }

    void display()
    {
        cout << "Contractor Salary: " << calculateSalary() << endl;
    }
};

int main()
{
    Employee *emp[3];

    emp[0] = new FullTimeEmployee(50000);
    emp[1] = new PartTimeEmployee(40, 500);
    emp[2] = new Contractor(60000, 10);

    for (int i = 0; i < 3; i++)
    {
        emp[i]->display();
    }

    for (int i = 0; i < 3; i++)
    {
        delete emp[i];
    }

    return 0;
}
