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

    for (int i = 0; i < 3; i++) {
        cout << "\nEnter details for patient " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> ws;
        getline(cin, patients[i].name);

        cout << "Age: ";
        cin >> patients[i].age;

        cout << "Disease: ";
        cin >> ws;
        getline(cin, patients[i].disease);
    }

    cout << "\nPatient Records:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nPatient " << i + 1 << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Disease: " << patients[i].disease << endl;
    }
system("pause");
    return 0;
}
