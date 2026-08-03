// Q5. Write a program with a class StudentClass having a private integer pointer
// and size. Write a dynamic constructor that takes an integer n, allocates
// an array of n integers on the heap, reads n student IDs from the user,
// and stores them. Write a display() function and a destructor that frees
// the allocated memory and prints "Memory freed".

#include <iostream>
using namespace std;

class StudentClass {
private:
    int *ids;
    int size;

public:
    StudentClass(int n) {
        size = n;
        ids = new int[size];

        cout << "Enter " << size << " student IDs:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> ids[i];
        }
    }

    void display() {
        cout << "Student IDs are:" << endl;
        for (int i = 0; i < size; i++) {
            cout << ids[i] << endl;
        }
    }

    ~StudentClass() {
        delete[] ids;
        cout << "Memory freed" << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    StudentClass s(n);
    s.display();

    return 0;
}