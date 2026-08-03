// Task 2: Create a structure Patient with fields name, age, and disease.
// Input and display records for 3 patients using an array of structures.

#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int age;
    string disease;
};

int main() {
    Patient patients[3];

    cout << "Enter details of 3 patients:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nPatient " << i + 1 << endl;

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, patients[i].name);

        cout << "Enter age: ";
        cin >> patients[i].age;

        cout << "Enter disease: ";
        cin >> ws;
        getline(cin, patients[i].disease);
    }

    cout << "\nPatient Records:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nPatient " << i + 1 << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Disease: " << patients[i].disease << endl;
    }

    return 0;
}