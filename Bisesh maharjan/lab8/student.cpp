#include <iostream>
#include <fstream>
using namespace std;
class Student{
public:
    int roll;
    char name[30];
    float marks;
};
int main(){
    Student s;
    ofstream outfile("students.dat", ios::binary);
    for(int i=1;i<=10;i++){
        s.roll = i;
        cout<<"Enter name for roll "<<i<<": ";
        cin>>s.name;
        cout<<"Enter marks: ";
        cin>>s.marks;
        outfile.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }
    outfile.close();
    ifstream infile("students.dat", ios::binary);
    cout<<endl<<"Student Records:"<<endl;
    while(infile.read(reinterpret_cast<char*>(&s), sizeof(Student))){
        cout<<s.roll<<" "<<s.name<<" "<<s.marks<<endl;
    }
    infile.close();
    int r;
    cout<<endl<<"Enter roll number to modify: ";
    cin>>r;
    fstream file("students.dat", ios::in|ios::out|ios::binary);
    file.seekg((r-1)*sizeof(Student));
    file.read(reinterpret_cast<char*>(&s), sizeof(Student));
    cout<<"Enter new name: ";
    cin>>s.name;
    cout<<"Enter new marks: ";
    cin>>s.marks;
    file.seekp((r-1)*sizeof(Student));
    file.write(reinterpret_cast<char*>(&s), sizeof(Student));
    file.close();
    return 0;
}
