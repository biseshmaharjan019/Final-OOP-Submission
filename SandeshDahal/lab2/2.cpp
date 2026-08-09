#include <iostream>
using namespace std;

struct Patient {
    string name;
    int age;
    string disease;
};

int main() {
    Patient p[3];

    for(int i = 0; i < 3; i++) {
        cout << "Enter name: ";
        cin >> p[i].name;

        cout << "Enter age: ";
        cin >> p[i].age;

        cout << "Enter disease: ";
        cin >> p[i].disease;
    }

    cout << "\nPatient Records:\n";

    for(int i = 0; i < 3; i++) {
        cout << "Name: " << p[i].name << endl;
        cout << "Age: " << p[i].age << endl;
        cout << "Disease: " << p[i].disease << endl;
    }

    return 0;
}