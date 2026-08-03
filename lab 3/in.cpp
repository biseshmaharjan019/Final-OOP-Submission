
#include<iostream>
using namespace std;

class Birthday
{
    int day, month, year;

    public:
    void getBirthday()
    {
        cout<<"Enter day month and year: ";
        cin>>day>>month>>year;
    }

    void displayBirthday()
    {
        cout<<day<<"/"<<month<<"/"<<year;
    }
};

class Employee
{
    int id;
    char name[20];

    Birthday b;   

    public:
    void getEmployee()
    {
        cout<<"Enter Employee ID: ";
        cin>>id;

        cout<<"Enter Employee Name: ";
        cin>>name;

        b.getBirthday();
    }

    void displayEmployee()
    {
        cout<<"\nEmployee ID: "<<id;
        cout<<"\nEmployee Name: "<<name;
        cout<<"\nBirthday: ";
        b.displayBirthday();
    }
};

int main()
{
    Employee e;

    e.getEmployee();
    e.displayEmployee();

    return 0;
}