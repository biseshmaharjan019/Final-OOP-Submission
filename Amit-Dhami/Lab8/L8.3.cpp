#include<iostream>
#include<fstream>
using namespace std;

class Student
{
public:
    int roll;
    char name[30];
    float marks;

    void input()
    {
        cout<<"Roll: ";
        cin>>roll;
        cout<<"Name: ";
        cin>>name;
        cout<<"Marks: ";
        cin>>marks;
    }

    void display()
    {
        cout<<roll<<"\t"<<name<<"\t"<<marks<<endl;
    }
};

int main()
{
    Student s;
    fstream file("students.dat",ios::out|ios::binary);

    for(int i=0;i<10;i++)
    {
        cout<<"\nStudent "<<i+1<<endl;
        s.input();
        file.write((char*)&s,sizeof(s));
    }

    file.close();

    file.open("students.dat",ios::in|ios::binary);

    cout<<"\nStudent Information\n";
    cout<<"Roll\tName\tMarks\n";

    while(file.read((char*)&s,sizeof(s)))
        s.display();

    file.close();

    int r;
    cout<<"\nEnter roll number to modify: ";
    cin>>r;

    file.open("students.dat",ios::in|ios::out|ios::binary);

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.roll==r)
        {
            cout<<"Enter new information:\n";
            s.input();

            file.seekp(-sizeof(s),ios::cur);
            file.write((char*)&s,sizeof(s));

            cout<<"Student information modified successfully."<<endl;
            break;
        }
    }

    file.close();

    return 0;
}
