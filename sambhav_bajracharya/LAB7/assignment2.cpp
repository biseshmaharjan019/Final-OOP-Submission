#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;

public:
    Employee(string n) {
        name = n;
    }

    virtual float calculateSalary() const = 0;
    virtual void display() const = 0;

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    float monthlySalary;

public:
    FullTimeEmployee(string n, float salary) : Employee(n) {
        monthlySalary = salary;
    }

    float calculateSalary() const override {
        return monthlySalary;
    }

    void display() const override {
        cout << "Full-Time Employee: " << name << " | Monthly Salary: $" << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(string n, int hours, float rate) : Employee(n) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    float calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }

    void display() const override {
        cout << "Part-Time Employee: " << name << " | Total Pay: $" << calculateSalary() << endl;
    }
};

class Contractor : public Employee {
private:
    float projectFee;
    float taxRate;

public:
    Contractor(string n, float fee, float tax) : Employee(n) {
        projectFee = fee;
        taxRate = tax;
    }

    float calculateSalary() const override {
        return projectFee - (projectFee * taxRate);
    }

    void display() const override {
        cout << "Contractor: " << name << " | Net Pay: $" << calculateSalary() << endl;
    }
};

int main() {
    Employee* employees[3];

    employees[0] = new FullTimeEmployee("John Smith", 5000.0f);
    employees[1] = new PartTimeEmployee("Sarah Lee", 80, 25.0f);
    employees[2] = new Contractor("Mike Brown", 4000.0f, 0.15f);

    cout << "Employee Details and Salary Processing" << endl;
    for (int i = 0; i < 3; i++) {
        employees[i]->display();
    }

    for (int i = 0; i < 3; i++) {
        delete employees[i];
    }

    return 0;
}
