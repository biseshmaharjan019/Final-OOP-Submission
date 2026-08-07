#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int    age;
    string disease;
};

int main() {
    Patient patients[3];

    cout << "Enter details for 3 patients:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nPatient " << i + 1 << ":\n";
        cout << "  Name   : "; cin >> patients[i].name;
        cout << "  Age    : "; cin >> patients[i].age;
        cout << "  Disease: "; cin >> patients[i].disease;
    }

    cout << "\n--- Patient Records ---\n";
    cout << "No.  Name       Age  Disease\n";
    cout << "---  ---------  ---  --------\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "    "
             << patients[i].name    << "       "
             << patients[i].age     << "   "
             << patients[i].disease << endl;
    }

    return 0;
}