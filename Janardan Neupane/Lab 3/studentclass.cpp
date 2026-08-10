#include <iostream>
using namespace std;
class StudentClass {
    int *arr;
    int size;
public:
    StudentClass(int n) {
        size = n;
        arr = new int[size];
        cout << "Enter " << size << " student IDs:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    void display() {
        cout << "Student IDs: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~StudentClass() {
        delete[] arr;
        cout << "Memory freed\n";
    }
};
int main() {
    StudentClass s(5);
    s.display();
}