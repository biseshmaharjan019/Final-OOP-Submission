#include <iostream>
#include <iomanip>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(name), id(id) {}
    virtual float calculateSalary() const = 0;
    virtual void display() const = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    float monthlySalary;
public:
    FullTimeEmployee(std::string name, int id, float salary)
        : Employee(name, id), monthlySalary(salary) {}

    float calculateSalary() const override {
        return monthlySalary;
    }

    void display() const override {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Name: " << name << " | ID: " << id << " | Type: Full-Time\n";
        std::cout << "Monthly Salary: $" << calculateSalary() << "\n\n";
    }
};

class PartTimeEmployee : public Employee {
    float hoursWorked;
    float hourlyRate;
public:
    PartTimeEmployee(std::string name, int id, float hours, float rate)
        : Employee(name, id), hoursWorked(hours), hourlyRate(rate) {}

    float calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }

    void display() const override {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Name: " << name << " | ID: " << id << " | Type: Part-Time\n";
        std::cout << "Hours: " << hoursWorked << " @ $" << hourlyRate << "/hr";
        std::cout << " | Pay: $" << calculateSalary() << "\n\n";
    }
};

class Contractor : public Employee {
    float projectFee;
    float taxRate;
public:
    Contractor(std::string name, int id, float fee, float tax)
        : Employee(name, id), projectFee(fee), taxRate(tax) {}

    float calculateSalary() const override {
        return projectFee - (projectFee * taxRate);
    }

    void display() const override {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Name: " << name << " | ID: " << id << " | Type: Contractor\n";
        std::cout << "Fee: $" << projectFee << " | Tax: " << (taxRate * 100) << "%";
        std::cout << " | Net: $" << calculateSalary() << "\n\n";
    }
};

class Intern : public Employee {
    float stipend;
public:
    Intern(std::string name, int id, float stipend)
        : Employee(name, id), stipend(stipend) {}

    float calculateSalary() const override {
        return stipend;
    }

    void display() const override {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Name: " << name << " | ID: " << id << " | Type: Intern\n";
        std::cout << "Stipend: $" << calculateSalary() << "\n\n";
    }
};

int main() {
    const int COUNT = 4;
    Employee* staff[COUNT] = {
        new FullTimeEmployee("Alice Johnson", 101, 5000.0f),
        new PartTimeEmployee("Bob Smith",     102, 80.0f, 25.0f),
        new Contractor      ("Carol White",   103, 8000.0f, 0.18f),
        new Intern          ("David Lee",     104, 1200.0f)
    };

    for (int i = 0; i < COUNT; i++) {
        staff[i]->display();
    }

    for (int i = 0; i < COUNT; i++) {
        delete staff[i];
    }

    return 0;
}