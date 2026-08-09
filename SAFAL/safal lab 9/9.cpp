#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
    T arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(T value)
    {
        if (top == 4)
            throw "Stack Overflow";

        arr[++top] = value;
    }

    T pop()
    {
        if (top == -1)
            throw "Stack Underflow";

        return arr[top--];
    }

    void display()
    {
        if (top == -1)
            throw "Stack Underflow";

        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    try
    {
        // Integer Stack
        Stack<int> intStack;

        intStack.push(10);
        intStack.push(20);
        intStack.push(30);

        cout << "Integer Stack: ";
        intStack.display();

        // String Stack
        Stack<string> stringStack;

        stringStack.push("Apple");
        stringStack.push("Banana");
        stringStack.push("Mango");

        cout << "String Stack: ";
        stringStack.display();

        // Uncomment to test overflow
        // intStack.push(40);
        // intStack.push(50);
        // intStack.push(60);

        // Uncomment to test underflow
        // intStack.pop();
        // intStack.pop();
        // intStack.pop();
        // intStack.pop();

    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}
