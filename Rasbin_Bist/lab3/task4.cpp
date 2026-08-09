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
        cout << "Constructor: " << deptName << " created\n";
    }
 
    
    ~Department() {
        cout << "Destructor: " << deptName << " going out of scope\n";
    }
};
 
int main() {
    cout << "Entering main block\n";
    Department d1(1, "HR");           
 
    {
        cout << "\nEntering inner block 1n";
        Department d2(2, "Finance"); 
        Department d3(3, "IT");        
        cout << "Leaving inner block 1\n";
        
    }
 
    {
        cout << "\nEntering inner block 2\n";
        Department d4(4, "Marketing");
        cout << "Leaving inner block 2 \n";

    }
 
    cout << "\nLeaving main block\n";
    
    return 0;
}
 