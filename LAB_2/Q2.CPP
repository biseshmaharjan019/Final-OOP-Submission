// Patient Record Using Structure

#include <iostream>
#include <cstdlib>
using namespace std;

struct Patient
{
    string name;
    int age;
    string disease;
};

int main()
{
    Patient p[3];

    for(int i = 0; i < 3; i++)
    {
        cout << "Enter name age disease: ";
        cin >> p[i].name >> p[i].age >> p[i].disease;
    }

    cout << "\nPatient Records:\n";

    for(int i = 0; i < 3; i++)
    {
        cout << p[i].name << " "
             << p[i].age << " "
             << p[i].disease << endl;
    }

    system("pause");
    return 0;
}