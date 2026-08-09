#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T, int SIZE = 3>
class Stack {
private:
    T arr[SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top >= SIZE - 1) {
            throw overflow_error("Stack Overflow: Cannot push onto a full stack.");
        }
        arr[++top] = val;
    }

    T pop() {
        if (top < 0) {
            throw underflow_error("Stack Underflow: Cannot pop from an empty stack.");
        }
        return arr[top--];
    }

    void display() const {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Testing Integer Stack" << endl;
    try {
        Stack<int, 3> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.display();

        intStack.push(40);
    } catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    cout << "\nTesting String Stack" << endl;
    try {
        Stack<string, 3> stringStack;
        stringStack.push("Apple");
        stringStack.push("Banana");
        stringStack.push("Cherry");
        stringStack.display();

        stringStack.pop();
        stringStack.pop();
        stringStack.pop();
        stringStack.pop();
    } catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}
