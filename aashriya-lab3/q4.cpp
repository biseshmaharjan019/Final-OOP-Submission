#include<iostream>
#include<string>
using namespace std;
class Department {
    private:
    int deptid;
    string deptname;
    public:
    Department(int id, string name){
        deptid = id;
        deptname = name;
        cout<<"dept1 created"<<endl;
    }
    void display(){
        cout<<"Department ID: "<<deptid<<endl;
        cout<<"Department Name: "<<deptname<<endl;
    }
    ~Department(){
        cout<<" dept1 going oout of scope"<<endl;
}};
int main(){
    Department dept1(101, "Computer Science");
    dept1.display();
    return 0;
}