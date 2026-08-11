#include <iostream>
using namespace std;

class Department {
    int deptID;
    string deptName;

public:
    Department(int id, string name) {
        deptID = id;
        deptName = name;
        cout << "Constructor: " << deptName << " created\n";
    }

    ~Department() {
        cout << "Destructor: " << deptName << " destroyed\n";
    }
};

int main() {

    {
        Department d1(1, "HR");
        {
            Department d2(2, "IT");
        } 
        Department d3(3, "Finance");
    } 

    return 0;
}
