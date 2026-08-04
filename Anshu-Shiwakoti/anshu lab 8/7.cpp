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
    Student s;
    fstream file("student.dat", ios::out | ios::binary);

    for (int i = 0; i < 10; i++) {
        cout << "Enter Roll Name Marks: ";
        cin >> s.roll >> s.name >> s.marks;
        file.write((char*)&s, sizeof(s));
    }

    file.close();

    file.open("student.dat", ios::in | ios::out | ios::binary);

    int r;
    cout << "Enter Roll to Modify: ";
    cin >> r;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.roll == r) {
            cout << "Enter New Name Marks: ";
            cin >> s.name >> s.marks;
            file.seekp(-sizeof(s), ios::cur);
            file.write((char*)&s, sizeof(s));
            break;
        }
    }

    file.close();

    file.open("student.dat", ios::in | ios::binary);

    cout << "\nStudent Records\n";
    while (file.read((char*)&s, sizeof(s))) {
        cout << s.roll << " " << s.name << " " << s.marks << endl;
    }

    file.close();
    return 0;
}