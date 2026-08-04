#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    Student s;

    fstream file("student.dat", ios::out | ios::binary);

    for(int i=0;i<10;i++)
    {
        cout<<"Roll: ";
        cin>>s.roll;

        cout<<"Name: ";
        cin>>s.name;

        cout<<"Marks: ";
        cin>>s.marks;

        file.write((char*)&s,sizeof(s));
    }

    file.close();

    int r;

    cout<<"\nEnter Roll Number to Modify: ";
    cin>>r;

    file.open("student.dat", ios::in|ios::out|ios::binary);

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.roll==r)
        {
            cout<<"New Name: ";
            cin>>s.name;

            cout<<"New Marks: ";
            cin>>s.marks;

            file.seekp(-sizeof(s),ios::cur);
            file.write((char*)&s,sizeof(s));

            break;
        }
    }

    file.close();

    cout<<"Record Updated";

    return 0;
}
