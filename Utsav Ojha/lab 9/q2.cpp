#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
    T arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(T value)
    {
        if(top == 4)
            throw "Stack Overflow";

        arr[++top] = value;
    }

    void pop()
    {
        if(top == -1)
            throw "Stack Underflow";

        cout << "Popped: " << arr[top--] << endl;
    }

    void display()
    {
        cout << "Stack Elements: ";

        for(int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    try
    {
        Stack<int> s1;

        s1.push(10);
        s1.push(20);
        s1.push(30);

        s1.display();

        Stack<string> s2;

        s2.push("Ram");
        s2.push("Shyam");
        s2.push("Hari");

        s2.display();

        s1.pop();
        s1.pop();
        s1.pop();
        s1.pop();      // Underflow
    }
    catch(const char *msg)
    {
        cout << msg << endl;
    }

    return 0;
}
