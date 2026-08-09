#include <iostream>
using namespace std;

class StudentClass
{
private:
    int *ptr;
    int size;

public:
    StudentClass(int n)
    {
        size = n;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter student ID " << i + 1 << ": ";
            cin >> ptr[i];
        }
    }

    ~StudentClass()
    {
        delete[] ptr;
        cout << "Memory freed" << endl;
    }

    void display()
    {
        cout << "Student IDs: ";
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    StudentClass students(n);
    students.display();

    return 0;
}