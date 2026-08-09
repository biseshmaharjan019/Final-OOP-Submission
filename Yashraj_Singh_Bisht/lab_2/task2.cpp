#include <iostream>
using namespace std;

struct Patient {
    string name;
    int age;
    string disease;
};

int main() {
    Patient patients[3];

    cout << "Enter details for 3 patients:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nPatient " << (i + 1) << " Details:" << endl;
        cout << "Enter Name: ";
        cin >> patients[i].name;
        cout << "Enter Age: ";
        cin >> patients[i].age;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, patients[i].disease);
    }

    cout << "\n================ Patient Records ================\n";
    for (int i = 0; i < 3; i++) {
        cout << "Patient " << (i + 1) << " -> Name: " << patients[i].name 
             << " | Age: " << patients[i].age 
             << " | Disease: " << patients[i].disease << endl;
    }
    cout << "=================================================\n";

    return 0;
}