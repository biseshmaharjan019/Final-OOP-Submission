#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    virtual float calculateSalary() = 0;
    virtual void display() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    string name;
    float monthlySalary;

public:
    FullTimeEmployee(string n, float salary) : name(n), monthlySalary(salary) {}

    float calculateSalary() override {
        return monthlySalary;
    }

    void display() override {
        cout << "Employee Type : Full-Time (" << name << ")" << endl;
        cout << "Calculated Net: $" << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    string name;
    float hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(string n, float hours, float rate) 
        : name(n), hoursWorked(hours), hourlyRate(rate) {}

    float calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    void display() override {
        cout << "Employee Type : Part-Time (" << name << ")" << endl;
        cout << "Calculated Net: $" << calculateSalary() << endl;
    }
};

class Contractor : public Employee {
private:
    string name;
    float projectFee;
    float taxRate; // decimal percentage e.g. 0.15

public:
    Contractor(string n, float fee, float tax) 
        : name(n), projectFee(fee), taxRate(tax) {}

    float calculateSalary() override {
        return projectFee - (projectFee * taxRate);
    }

    void display() override {
        cout << "Employee Type : Contractor (" << name << ")" << endl;
        cout << "Calculated Net: $" << calculateSalary() << endl;
    }
};

int main() {
    Employee* employees[3];
    employees[0] = new FullTimeEmployee("Nishchal", 6500.0f);
    employees[1] = new PartTimeEmployee("Siddhant", 120.0f, 25.0f);
    employees[2] = new Contractor("Aashray", 8000.0f, 0.10f);

    cout << "--- Payroll Summary ---" << endl;
    for (int i = 0; i < 3; i++) {
        employees[i]->display();
        cout << "-----------------------" << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete employees[i];
    }

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}