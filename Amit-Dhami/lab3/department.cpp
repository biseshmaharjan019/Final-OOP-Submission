#include <iostream>
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
cout << "Constructor: " << deptName << " created\n";
    }

    ~Department()
    {
        cout << "Destructor: " << deptName << " going out of scope\n";
    }
};
int main()
{
Department d1(1, "Admin");
{
Department d2(2, "Finance");
{
    Department d3(3, "HR");
        }}
return 0;
}
