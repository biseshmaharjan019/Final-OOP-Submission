//WAP to enter the records of 3 patients
#include<iostream>
using namespace std;
struct patient
{
    char name[20];
    int age;
    char disease[20];
};
int main()
{
    struct patient s[3];
    int i;
    for(i=0;i<3;i++){
        cout<<"enter the name, age and disease of patient"<<i+1;
        cin>>s[i].name>>s[i].age>>s[i].disease;
    }
    cout<<"the records are \n";
    for(i=0;i<3;i++)
    {
        cout<<s[i].name<<" "<<s[i].age<<" "<<s[i].disease<<"\n";
    }
    return 0;
}
