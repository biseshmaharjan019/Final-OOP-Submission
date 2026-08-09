#include<iostream>
#include<fstream>
using namespace std;
class student{
public:
    int roll;
    char name[30];
    float marks;
    void input(){
        cout << "Enter Roll No.: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void display(){
        cout << "Roll No.: " << roll <<endl;
        cout << "Name: " << name <<endl;
        cout << "Marks: " << marks <<endl;
    }

};
int main()
{
    student s[10];
    for(int i=0;i<10;i++){
        cout << "\nStudent " <<i+1 <<endl;
        s[i].input();
    }
    fstream file("students.dat",ios::out|ios::binary);
    file.write((char*)s,sizeof(s));
    file.close();
    file.open("students.dat",ios::in|ios::binary);
    file.read((char*)s,sizeof(s));
    file.close();
    cout << "\nAll Students:\n";
    for(int i=0;i<10;i++){
        s[i].display();
    }
    int searchRoll;
    cout << "\nEnter roll number to modify: ";
    cin >> searchRoll;
    bool found=false;
    for(int i=0;i<10;i++){
        if(s[i].roll==searchRoll){
            found=true;
            cout << "New name: ";
            cin >> s[i].name;
            cout << "New marks: ";
            cin >> s[i].marks;
            break;
        }
    }
    if(found){
        file.open("students.dat",ios::out|ios::binary);
        file.write((char*)s,sizeof(s));
        file.close();
        cout << "Record updated.\n";
    }
    else{
        cout << "Roll number not found.\n";
    }
    return 0;
}
