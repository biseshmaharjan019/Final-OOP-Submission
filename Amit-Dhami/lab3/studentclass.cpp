#include <iostream>
using namespace std;
class StudentClass
{
    int *ptr;
    int size;
public:
    StudentClass(int n)
    {
    size = n;
        ptr = new int[size];
cout << "Enter Student IDs:\n";
for (int i = 0; i < size; i++)
            cin >> ptr[i];
    }
void display()
    {
        cout << "Student IDs:\n";
for (int i = 0; i < size; i++)
    cout << ptr[i] << " ";
        cout << endl;
    }

    ~StudentClass()
    {
        delete[] ptr;
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
