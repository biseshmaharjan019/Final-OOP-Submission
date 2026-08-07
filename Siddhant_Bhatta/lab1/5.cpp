#include <iostream>
#include <string>
using namespace std;

void inputEmployee(string &name, int &id, float &salary)
{
    cout << "Enter Employee Name: ";
    getline(cin >> ws, name);
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Salary: ";
    cin >> salary;
}

void printEmployee(string name, int id, float salary)
{
    cout << "\n--- Employee Details ---" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Salary: " << salary << endl;
}

int main()
{
    string name;
    int id;
    float salary;

    inputEmployee(name, id, salary);
    printEmployee(name, id, salary);

    return 0;
}