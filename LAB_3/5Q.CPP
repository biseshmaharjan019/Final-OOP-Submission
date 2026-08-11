// 5. StudentClass with Dynamic Constructor and Memory Allocation

#include <iostream>
using namespace std;

class StudentClass
{
    int *id;
    int size;

public:
    StudentClass(int n)
    {
        size = n;
        id = new int[size];

        cout << "Enter Student IDs:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> id[i];
        }
    }

    void display() const
    {
        cout << "Student IDs: ";
        for (int i = 0; i < size; i++)
        {
            cout << id[i] << " ";
        }
        cout << endl;
    }

    ~StudentClass()
    {
        delete[] id;
        cout << "Memory freed" << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    StudentClass s(n);
    s.display();

    return 0;
}