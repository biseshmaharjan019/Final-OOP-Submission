#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int rollNo;
    char name[30];
    float gpa;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void display() const {
        cout << "Roll No: " << rollNo << " | Name: " << name << " | GPA: " << gpa << endl;
    }
};

void createRecords() {
    ofstream outFile("students.dat", ios::binary);
    Student s;
    cout << "--- Entering 10 Student Records ---" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        s.input();
        outFile.write(reinterpret_cast<char*>(&s), sizeof(s));
    }
    outFile.close();
}

void modifyRecord(int searchRoll) {
    fstream file("students.dat", ios::binary | ios::in | ios::out);
    Student s;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.rollNo == searchRoll) {
            cout << "\nRecord found! Enter new details:" << endl;
            s.input();
            
            streampos pos = file.tellg() - static_cast<streamoff>(sizeof(s));
            file.seekp(pos);
            file.write(reinterpret_cast<char*>(&s), sizeof(s));
            found = true;
            cout << "Record updated successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << searchRoll << " not found." << endl;
    }
    file.close();
}

void displayRecords() {
    ifstream inFile("students.dat", ios::binary);
    Student s;
    cout << "\n--- Student Records ---" << endl;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.display();
    }
    inFile.close();
}

int main() {
    createRecords();
    displayRecords();

    int searchRoll;
    cout << "\nEnter Roll Number to modify: ";
    cin >> searchRoll;

    modifyRecord(searchRoll);
    displayRecords();

    return 0;
}
