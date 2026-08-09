
//5. Write a program with a class StudentClass having a private integer pointer and size.
// Write a dynamic constructor that takes an integer n, allocates an array of n integers on the heap,
// reads n student IDs from the user, and stores them.
// Write a display() function and a destructor that frees the allocated memory and prints "Memory freed". [8]

#include<iostream>
using namespace std;


class StudentClass {
private:
    int* studentIDs;
    int  size;

public:
    StudentClass(int n) {
        size       = n;
        studentIDs = new int[n];

        cout << "Enter " << n << " student ID(s):\n";
        for (int i = 0; i < n; i++) {
            cout << "Student " << (i + 1) << ": ";
            cin  >> studentIDs[i];
        }
    }

    void display() {
        cout << "\nStored Student IDs:\n";
        for (int i = 0; i < size; i++) {
            cout << "  [" << (i + 1) << "] " << studentIDs[i] << "\n";
        }
    }

    ~StudentClass() {
        delete[] studentIDs;
        cout << "Memory freed\n";
    }
};

int main() {
    int n;
    cout << "How many students? ";
    cin  >> n;

    StudentClass sc(n);
    sc.display();

    return 0;
}