#include<iostream>
using namespace std;

class Department{
    int deptID;
    string deptName;
public:
    Department(int id, string name){
        deptID = id; deptName = name;
        cout<<"Constructor: "<<deptName<<" created"<<endl;
    }
    ~Department(){
        cout<<"Destructor: "<<deptName<<" going out of scope"<<endl;
    }
};

int main(){
    Department d1(1, "Civil");
    {
        Department d2(2, "Electronics");
        {
            Department d3(3, "Computer");
        }
    }
    return 0;
}
