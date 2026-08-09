#include <iostream>
using namespace std;
struct patient
{
    char name[20];
    int age;
    char disease[20];
};

int main()
{
    patient p[3];
    int i;
    for(i = 0; i < 3; i++)
    {
        cout << "Enter name of patient : ";
        cin >> p[i].name;

        cout << "Enter age of patient : ";
        cin >> p[i].age;
        cout << "Enter disease of patient : ";
        cin >> p[i].disease;
    }
    cout << "\nPatient Details:\n";
     for(i = 0; i < 3; i++)
    {
        cout << "\nPatient " << i + 1 << endl;
        cout << "Name : " << p[i].name << endl;
        cout << "Age : " << p[i].age << endl;
        cout << "Disease : " << p[i].disease << endl;
    }
    return 0;
}