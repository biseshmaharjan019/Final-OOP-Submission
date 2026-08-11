#include <iostream>
using namespace std;

class StudentClass {
private:
    int *ptr;
    int size;

public:
    StudentClass(int n) {
        size = n;
        ptr = new int[size];

        cout << "Enter " << size << " student IDs:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> ptr[i];
        }
    }

    void display() {
        cout << "\nStudent IDs:" << endl;
        for (int i = 0; i < size; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    ~StudentClass() {
        delete[] ptr;
        cout << "Memory freed." << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    StudentClass students(n);
    students.display();

    system("pause");
    return 0;
}
