#include<iostream>
using namespace std;
class Employee{
public:
    virtual void calculateSalary()=0;
};
class Manager: public Employee{
private:
    float basic;
public:
    Manager(float b){
        basic=b;
    }
    void calculateSalary(){
        float salary=basic+(0.30*basic);
        cout << "Manager Salary = " <<salary <<endl;
    }
};
class Developer: public Employee{
private:
    float basic;
public:
    Developer(float b){
        basic=b;
    }
    void calculateSalary(){
        float salary=basic+(0.20*basic);
        cout << "Developer Salary = " <<salary <<endl;
    }
};
class Intern: public Employee{
private:
    float stipend;
public:
    Intern(float s){
        stipend=s;
    }
    void calculateSalary(){
        cout << "Intern Salary = " <<stipend <<endl;
    }
};
int main()
{
    Employee *emp[3];
    Manager m(50000);
    Developer d(40000);
    Intern i(15000);
    emp[0]=&m;
    emp[1]=&d;
    emp[2]=&i;
    cout << "Employee Salaries:\n";
    for(int j=0;j<3;j++){
        emp[j]->calculateSalary();
    }
    return 0;
}
