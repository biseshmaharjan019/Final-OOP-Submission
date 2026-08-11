// Department Constructor and Destructor

#include <iostream>
#include <cstdlib>
using namespace std;

class Department
{
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
    {
        Department d1(1, "CSE");

        {
            Department d2(2, "ECE");
        }
    }

    system("pause");
    return 0;
}