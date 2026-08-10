// Define a class rectangle with length and breadth as appropriate and private member to read data
//  member ,calculate and display area write a main program to read leangth ,breadth and diaplay area
#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length;
    float breadth;
    void readData()
    {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
    }

public:
    void Display()
    {
        readData();
        float area = length * breadth;
        cout << "Area of Rectangle: " << area << endl;
    }
};

int main()
{
    Rectangle rect;
    rect.Display();
    return 0;
}
