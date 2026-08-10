#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <class T>
class Stack {
private:
    T items[3];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(T value) {
        if (top == 2)
            throw overflow_error("Stack Overflow: Stack is full.");

        items[++top] = value;
    }

    T pop() {
        if (top == -1)
            throw underflow_error("Stack Underflow: Stack is empty.");

        return items[top--];
    }

    void display() const {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
            cout << items[i] << " ";

        cout << endl;
    }
};

int main() {
    Stack<int> intStack;
    Stack<string> stringStack;

    try {
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);

        cout << "Integer Stack: ";
        intStack.display();

        // Uncomment the next line to test overflow.
        // intStack.push(40);

        cout << "Popped integer: " << intStack.pop() << endl;
    }
    catch (const overflow_error& e) {
        cout << e.what() << endl;
    }
    catch (const underflow_error& e) {
        cout << e.what() << endl;
    }

    try {
        stringStack.push("Apple");
        stringStack.push("Banana");
        stringStack.push("Mango");

        cout << "\nString Stack: ";
        stringStack.display();

        // Uncomment the next lines to test underflow.
        // stringStack.pop();
        // stringStack.pop();
        // stringStack.pop();
        // stringStack.pop();
    }
    catch (const overflow_error& e) {
        cout << e.what() << endl;
    }
    catch (const underflow_error& e) {
        cout << e.what() << endl;
    }

    system("pause");
    return 0;
}
