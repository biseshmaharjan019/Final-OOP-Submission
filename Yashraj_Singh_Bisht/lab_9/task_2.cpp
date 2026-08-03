#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T arr[5];
    int top;
public:
    Stack() {
        top = -1;
    }
    
    void push(T val) {
        if (top >= 4) {
            throw "Stack Overflow Exception";
        }
        arr[++top] = val;
    }
    
    void pop() {
        if (top == -1) {
            throw "Stack Underflow Exception";
        }
        top--;
    }
    
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
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
        cout << "Integer Stack: ";
        intStack.display();
        
        Stack<string> stringStack;
        stringStack.push("Apple");
        stringStack.push("Banana");
        stringStack.push("Cherry");
        cout << "String Stack: ";
        stringStack.display();
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }
    return 0;
}
