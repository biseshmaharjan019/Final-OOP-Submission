#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int age;
    string disease;
};

int main() {
    Patient p[3];
    int i;
    for (i = 0; i < 3; i++) {
        cout << "Patient " << i + 1 << ":" << endl;
        cout << "Name:";
        cin>>p[i].name;
        cout << "Age:";
        cin >> p[i].age;
        cout << "Disease:";
        cin>>p[i].disease;
        cout << endl;
    }
    cout << "No.\tName\tAge\tDisease" << endl;
    for (i = 0; i < 3; i++)
        cout << i + 1 << "\t" << p[i].name << "\t" << p[i].age << "\t" << p[i].disease << endl;
    return 0;
}
