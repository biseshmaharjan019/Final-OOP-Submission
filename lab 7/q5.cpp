#include<iostream>
using namespace std;

class Employee{
public:
    virtual float calculateSalary()=0;
    virtual void display()=0;
};

class FullTimeEmployee:public Employee{
public:
    float calculateSalary()
    {
        return 50000;
    }

    void display()
    {
        cout<<"Full Time Salary = "<<calculateSalary()<<endl;
    }
};

class PartTimeEmployee:public Employee{
public:
    float calculateSalary()
    {
        return 20*500;
    }

    void display()
    {
        cout<<"Part Time Salary = "<<calculateSalary()<<endl;
    }
};

class Contractor:public Employee{
public:
    float calculateSalary()
    {
        return 50000-5000;
    }

    void display()
    {
        cout<<"Contractor Salary = "<<calculateSalary()<<endl;
    }
};

int main()
{
    Employee *e[3];

    e[0]=new FullTimeEmployee;
    e[1]=new PartTimeEmployee;
    e[2]=new Contractor;

    for(int i=0;i<3;i++)
    {
        e[i]->display();
        delete e[i];
    }

    return 0;
}