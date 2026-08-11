#include <iostream>
#include <string>
using namespace std;

#define MAX 5

template <typename T>
class Stack {
private:
    T arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top >= MAX - 1) {
            throw "Stack Overflow!";
        }
        arr[++top] = val;
    }

    T pop() {
        if (top < 0) {
            throw "Stack Underflow!";
        }
        return arr[top--];
    }

    void display() const {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        cout << "Integer Stack contents: ";
        intStack.display();
        
        cout << "Popped element: " << intStack.pop() << endl;
        cout << "After pop: ";
        intStack.display();

        cout << endl;

        Stack<string> strStack;
        strStack.push("Apple");
        strStack.push("Banana");
        strStack.push("Cherry");
        cout << "String Stack contents: ";
        strStack.display();

    } catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    cout << "\nTesting Stack Underflow:" << endl;
    try {
        Stack<int> emptyStack;
        emptyStack.pop();
    } catch (const char* msg) {
        cout << "Caught Exception: " << msg << endl;
    }

    cout << "\nTesting Stack Overflow:" << endl;
    try {
        Stack<int> fullStack;
        for (int i = 1; i <= 6; i++) {
            fullStack.push(i * 10);
        }
    } catch (const char* msg) {
        cout << "Caught Exception: " << msg << endl;
    }

    return 0;
}