#include<iostream>
using namespace std;

class Department {
    private:
        int deptID;
        string deptName;
    public:
        Department(int id,string name) 
		{
            deptID=id;
            deptName=name;
            cout<< "Constructor: "<< deptName<<" created"<<endl;
        }

        ~Department() {
            cout<<"Destructor: "<<deptName<<" going out of scope"<<endl;
        }
};

int main() {
    cout<<"Entering main block"<<endl;
    Department d1(1,"Science");
    cout<<endl<<"Entering block 1"<<endl;
    Department d2(2,"Math");
    Department d3(3,"English");
    cout<<"Leaving block 1"<<endl;
    cout<<endl<<"Entering block 2"<<endl;
    Department d4(4,"Computer");
    cout<<"Leaving block 2"<<endl;
    cout<<endl<<"Leaving main block"<<endl;
    return 0;
}
