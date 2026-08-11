// Multilevel Inheritance Constructor and Destructor Execution Order

#include <iostream>
#include <cstdlib>
using namespace std;

class A
{
    int value;

public:
    A(int v) : value(v)
    {
        cout << "A constructor: value = " << value << endl;
    }

    ~A()
    {
        cout << "A destructor: value = " << value << endl;
    }
};

class B : public A
{
    int valueB;

public:
    B(int a, int b) : A(a), valueB(b)
    {
        cout << "B constructor: value = " << valueB << endl;
    }

    ~B()
    {
        cout << "B destructor: value = " << valueB << endl;
    }
};

class C : public B
{
    int valueC;

public:
    C(int a, int b, int c) : B(a, b), valueC(c)
    {
        cout << "C constructor: value = " << valueC << endl;
    }

    ~C()
    {
        cout << "C destructor: value = " << valueC << endl;
    }
};

int main()
{
    C obj1(1, 10, 100);
    C obj2(2, 20, 200);

    system("pause");
    return 0;
}