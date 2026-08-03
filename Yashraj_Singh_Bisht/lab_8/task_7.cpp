#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int roll;
    char name[30];
    float marks;
};

int main() {
    ofstream outFile("students.dat", ios::binary);
    Student s[10];
    for (int i = 0; i < 10; i++) {
        s[i].roll = i + 1;
        strcpy(s[i].name, "Student");
        s[i].marks = 70.0 + i;
    }
    outFile.write((char*)&s, sizeof(s));
    outFile.close();

    fstream file("students.dat", ios::in | ios::out | ios::binary);
    int targetRoll;
    cout << "Enter roll number to modify: ";
    cin >> targetRoll;

    Student temp;
    bool found = false;
    while (file.read((char*)&temp, sizeof(Student))) {
        if (temp.roll == targetRoll) {
            cout << "Current Data - Name: " << temp.name << ", Marks: " << temp.marks << endl;
            cout << "Enter new marks: ";
            cin >> temp.marks;

            int pos = (int)file.tellg() - sizeof(Student);
            file.seekp(pos);
            file.write((char*)&temp, sizeof(Student));
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Record updated successfully." << endl;
    } else {
        cout << "Student record not found." << endl;
    }
    file.close();
    return 0;
}
