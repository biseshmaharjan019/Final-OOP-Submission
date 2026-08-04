#include <iostream>
using namespace std;

class Box
{
private:
    float l, b, h;

public:
    Box()
    {
        l = 1.0;
        b = 1.0;
        h = 1.0;
        cout << "Default constructor called" << endl;
    }

    Box(float len, float bre, float hei)
    {
        l = len;
        b = bre;
        h = hei;
        cout << "Parameterized constructor called" << endl;
    }

    Box(float len, float bre = 2.0)
    {
        l = len;
        b = bre;
        h = 3.0;
        cout << "Constructor with default arguments called" << endl;
    }

    Box(const Box &obj)
    {
        l = obj.l;
        b = obj.b;
        h = obj.h;
        cout << "Copy constructor called" << endl;
    }

    ~Box()
    {
        cout << "Destructor called: Object destroyed (" << l << ", " << b << ", " << h << ")" << endl;
    }
};

int main()
{
    cout << "Creating b1: " << endl;
    Box b1;

    cout << "\nCreating b2: " << endl;
    Box b2(5.5, 4.2, 3.1);

    cout << "\nCreating b3: " << endl;
    Box b3(7.5);

    cout << "\nCreating b4: " << endl;
    Box b4(b2);

    cout << "\nExiting main..." << endl;
    return 0;
}