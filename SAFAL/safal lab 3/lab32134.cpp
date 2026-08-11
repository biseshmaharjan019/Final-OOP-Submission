#include <iostream>
using namespace std;
class StudentClass
{
    int *ids;
    int size;
public:
    StudentClass(int n)
    {
        size = n;
        ids = new int[size];
        cout << "Enter Student IDs:\n";
        for (int i = 0; i < size; i++)
            cin >> ids[i];
    }
    void display()
    {
        cout << "Student IDs:\n";

        for (int i = 0; i < size; i++)
            cout << ids[i] << " ";

        cout << endl;
    }
    ~StudentClass()
    {
        delete[] ids;
        cout << "Memory freed\n";
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
