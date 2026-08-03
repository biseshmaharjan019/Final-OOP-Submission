// Q4. Write a program with a class Department having private members deptID
// and deptName. Write a constructor that prints "Constructor: [name] created"
// and a destructor that prints "Destructor: [name] going out of scope".
// Create objects inside different blocks in main and list the exact order
// in which constructors and destructors are called.

#include <iostream>
#include <string>
using namespace std;

class Department {
private:
    int deptID;
    string deptName;

public:
    Department(int id, string name) {
        deptID = id;
        deptName = name;
        cout << "Constructor: " << deptName << " created" << endl;
    }

    ~Department() {
        cout << "Destructor: " << deptName << " going out of scope" << endl;
    }
};

int main() {
    Department d1(1, "Computer");

    {
        Department d2(2, "Electronics");

        {
            Department d3(3, "Civil");
        }

        Department d4(4, "Mechanical");
    }

    return 0;
}