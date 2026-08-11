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
    cout << "Entering first block..." << endl;
    {
        Department d1(1, "Computer");
        Department d2(2, "Electronics");
    }

    cout << "\nEntering second block..." << endl;
    {
        Department d3(3, "Civil");
        Department d4(4, "Mechanical");
    }

    cout << "\nOrder of calls:" << endl;
    cout << "Constructors are called in creation order." << endl;
    cout << "Destructors are called in reverse order within each block." << endl;

    system("pause");
    return 0;
}
