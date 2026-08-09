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
    float monthlySalary;
public:
    FullTimeEmployee(float salary) : monthlySalary(salary) {}
    float calculateSalary() override {
        return monthlySalary;
    }
    void display() override {
        cout << "Full-Time Employee Salary: Rs. " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    float hoursWorked;
    float hourlyRate;
public:
    PartTimeEmployee(float hours, float rate) : hoursWorked(hours), hourlyRate(rate) {}
    float calculateSalary() override {
        return hoursWorked * hourlyRate;
    }
    void display() override {
        cout << "Part-Time Employee Salary: Rs. " << calculateSalary() << endl;
    }
};

class Contractor : public Employee {
private:
    float projectFee;
    float taxRate;
public:
    Contractor(float fee, float tax) : projectFee(fee), taxRate(tax) {}
    float calculateSalary() override {
        return projectFee - (projectFee * taxRate / 100.0f);
    }
    void display() override {
        cout << "Contractor Salary: Rs. " << calculateSalary() << endl;
    }
};

int main() {
    Employee* employees[3];
    employees[0] = new FullTimeEmployee(50000.0f);
    employees[1] = new PartTimeEmployee(80.0f, 500.0f);
    employees[2] = new Contractor(100000.0f, 10.0f);

    for (int i = 0; i < 3; i++) {
        employees[i]->display();
        delete employees[i];
    }

    return 0;
}