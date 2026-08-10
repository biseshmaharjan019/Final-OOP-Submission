#include <iostream>

using namespace std;

class StudentClass {
private:
    int* studentIDs;
    int size;

public:
    StudentClass(int n) {
        size = n;
        studentIDs = new int[size];

        cout << "Enter " << size << " student IDs:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "ID " << i + 1 << ": ";
            cin >> studentIDs[i];
        }
    }

    void display() {
        cout << "\nStudent IDs stored: ";
        for (int i = 0; i < size; i++) {
            cout << studentIDs[i] << " ";
        }
        cout << endl;
    }

    ~StudentClass() {
        delete[] studentIDs;
        cout << "Memory freed" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    StudentClass s1(n);
    s1.display();

    return 0;
}

