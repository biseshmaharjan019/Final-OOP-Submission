#include <iostream>
#include <string>
using namespace std;

class Department
{
private:
    int deptID;
    string deptName;

public:
    Department(int id, string name)
    {
        deptID = id;
        deptName = name;
        cout << "Constructor: " << deptName << " created" << endl;
    }

    ~Department()
    {
        cout << "Destructor: " << deptName << " going out of scope" << endl;
    }
};

int main()
{
    cout << "Entering main block" << endl;
    Department d1(1, "HR");

    {
        cout << "\nEntering Inner Block 1" << endl;
        Department d2(2, "IT");
        cout << "Exiting Inner Block 1" << endl;
    }

    {
        cout << "\nEntering Inner Block 2" << endl;
        Department d3(3, "Finance");
        cout << "Exiting Inner Block 2" << endl;
    }

    cout << "\nExiting main block" << endl;
    return 0;
}