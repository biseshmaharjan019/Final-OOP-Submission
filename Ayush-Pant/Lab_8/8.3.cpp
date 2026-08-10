#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char name[30];
    float marks;
};

int main() {
    ofstream fout("students.dat", ios::binary);
    Student s;
    for (int i = 0; i < 10; i++) {
        cout << "Enter roll, name, marks: ";
        cin >> s.roll >> s.name >> s.marks;
        fout.write((char*)&s, sizeof(s));
    }
    fout.close();

    int searchRoll;
    cout << "Enter roll number to modify: ";
    cin >> searchRoll;

    fstream file("students.dat", ios::in | ios::out | ios::binary);
    Student temp;
    bool found = false;
    while (file.read((char*)&temp, sizeof(temp))) {
        if (temp.roll == searchRoll) {
            cout << "Enter new name and marks: ";
            cin >> temp.name >> temp.marks;
            file.seekp(-(int)sizeof(temp), ios::cur);
            file.write((char*)&temp, sizeof(temp));
            found = true;
            break;
        }
    }
    file.close();

    if (found) cout << "Updated" << endl;
    else cout << "Not found" << endl;
}
