// Box Class with Constructors and Destructor
#include <iostream>
#include <cstdlib>
using namespace std;

class Box
{
    float l, b, h;

public:
    Box()
    {
        l = b = h = 0;
        cout << "Default Constructor Called" << endl;
    }

    Box(float x, float y, float z)
    {
        l = x;
        b = y;
        h = z;
        cout << "Parameterized Constructor Called" << endl;
    }

    Box(float x, float y = 1)
    {
        l = x;
        b = y;
        h = 1;
        cout << "Constructor with Default Arguments Called" << endl;
    }

    Box(const Box &obj)
    {
        l = obj.l;
        b = obj.b;
        h = obj.h;
        cout << "Copy Constructor Called" << endl;
    }

    ~Box()
    {
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    Box b1;
    Box b2(2, 3, 4);
    Box b3(5);
    Box b4(b2);

    system("pause");
    return 0;
}