#include <iostream>
using namespace std;

struct Patient {
    string name;
    int age;
    string disease;
};

int main() {
    Patient p[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter details for Patient " << i + 1 << ":" << endl;
        cout << "  Name   : ";
        cin >> p[i].name;
        cout << "  Age    : ";
        cin >> p[i].age;
        cout << "  Disease: ";
        cin >> p[i].disease;
        cout << endl;
    }

    cout << "Patient Records" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Patient " << i + 1 << ":" << endl;
        cout << "  Name   : " << p[i].name    << endl;
        cout << "  Age    : " << p[i].age     << endl;
        cout << "  Disease: " << p[i].disease << endl;
        cout << endl;
    }

    return 0;
}