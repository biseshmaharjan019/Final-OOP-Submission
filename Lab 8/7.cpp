#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int roll;
    char name[50];
    float marks;

    void getData() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void showData() const {
        cout << "Roll: " << roll << " | Name: " << name << " | Marks: " << marks << endl;
    }
};

int main() {
    fstream file("students.dat", ios::in | ios::out | ios::binary | ios::trunc);
    Student s;

    cout << "--- Enter Information for 10 Students ---" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        s.getData();
        file.write(reinterpret_cast<char*>(&s), sizeof(s));
    }

    file.seekg(0, ios::beg);
    cout << "\n--- Displaying All Students ---" << endl;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.showData();
    }

    int targetRoll;
    cout << "\nEnter Roll Number to modify: ";
    cin >> targetRoll;

    file.clear();
    file.seekg(0, ios::beg);
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.roll == targetRoll) {
            cout << "Matching record found. Enter new details:" << endl;
            s.getData();
            int pos = static_cast<int>(file.tellg()) - sizeof(s);
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&s), sizeof(s));
            found = true;
            cout << "Record updated successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << targetRoll << " not found." << endl;
    }

    file.clear();
    file.seekg(0, ios::beg);
    cout << "\n--- Updated Student List ---" << endl;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.showData();
    }

    file.close();
    return 0;
}