
//4. Write a program with a class Department having private members deptID and deptName.
// Write a parameterised constructor that prints "Constructor: [name] created" and a destructor that prints "Destructor: [name] going out of scope".

// Create objects inside different blocks in main and list the exact order in which constructors and destructors are called. [6]
#include <iostream>
#include <string>
using namespace std;

class Department {
private:
    int    deptID;
    string deptName;

public:
    Department(int id, string name) {
        deptID   = id;
        deptName = name;
        cout << "Constructor: " << deptName << " created\n";
    }

    ~Department() {
        cout << "Destructor: " << deptName << " going out of scope\n";
    }
};

int main() {
    cout << "\n[main block starts]\n";
    Department d1(101, "HR");

    {
        cout << "\n[Inner block 1 starts]\n";
        Department d2(102, "Finance");
        Department d3(103, "IT");
        cout << "[Inner block 1 ends]\n";
    }

    {
        cout << "\n[Inner block 2 starts]\n";
        Department d4(104, "Marketing");
        cout << "[Inner block 2 ends]\n";
    }

    cout << "\n[main block ends]\n";
    return 0;
}