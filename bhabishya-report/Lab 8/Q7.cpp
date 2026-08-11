#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    Student students[10];

    cout << "Enter information for 10 students:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Roll No: ";
        cin >> students[i].rollNo;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Marks: ";
        cin >> students[i].marks;
    }

    ofstream outFile("students.dat", ios::binary);

    if (!outFile) {
        cout << "Error opening file." << endl;
        system("pause");
        return 1;
    }

    /*
    string objects cannot safely be written directly as raw binary
    records, so the fields are written individually.
    */

    for (int i = 0; i < 10; i++) {
        outFile.write((char*)&students[i].rollNo, sizeof(students[i].rollNo));

        int nameLength = students[i].name.length();
        outFile.write((char*)&nameLength, sizeof(nameLength));
        outFile.write(students[i].name.c_str(), nameLength);

        outFile.write((char*)&students[i].marks, sizeof(students[i].marks));
    }

    outFile.close();

    cout << "\nStudent records stored successfully." << endl;

    int searchRoll;
    cout << "\nEnter roll number to modify: ";
    cin >> searchRoll;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "Error opening student file." << endl;
        system("pause");
        return 1;
    }

    bool found = false;

    for (int i = 0; i < 10; i++) {
        streampos recordStart = file.tellg();

        int roll;
        int nameLength;
        float marks;

        file.read((char*)&roll, sizeof(roll));
        file.read((char*)&nameLength, sizeof(nameLength));

        string name(nameLength, ' ');
        file.read(&name[0], nameLength);

        file.read((char*)&marks, sizeof(marks));

        if (roll == searchRoll) {
            found = true;

            string newName;
            float newMarks;

            cout << "Current Name: " << name << endl;
            cout << "Current Marks: " << marks << endl;

            cout << "Enter new name: ";
            cin >> newName;

            cout << "Enter new marks: ";
            cin >> newMarks;

            /*
            Because the name can have a different length, rewrite the
            complete file using a temporary file for safe modification.
            */
            file.close();

            ifstream oldFile("students.dat", ios::binary);
            ofstream tempFile("temp.dat", ios::binary);

            for (int j = 0; j < 10; j++) {
                int r, len;
                float m;

                oldFile.read((char*)&r, sizeof(r));
                oldFile.read((char*)&len, sizeof(len));

                string n(len, ' ');
                oldFile.read(&n[0], len);

                oldFile.read((char*)&m, sizeof(m));

                if (r == searchRoll) {
                    n = newName;
                    m = newMarks;
                }

                tempFile.write((char*)&r, sizeof(r));

                int newLen = n.length();
                tempFile.write((char*)&newLen, sizeof(newLen));
                tempFile.write(n.c_str(), newLen);

                tempFile.write((char*)&m, sizeof(m));
            }

            oldFile.close();
            tempFile.close();

            remove("students.dat");
            rename("temp.dat", "students.dat");

            cout << "Student information modified successfully." << endl;
            break;
        }
    }

    if (file.is_open())
        file.close();

    if (!found)
        cout << "Student with roll number " << searchRoll
             << " not found." << endl;

    system("pause");
    return 0;
}
