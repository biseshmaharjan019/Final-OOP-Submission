#include <iostream>
#include <string>
#include <stdexcept>

template <typename T, int SIZE = 5>
class Stack {
private:
    T arr[SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top >= SIZE - 1) {
            throw std::overflow_error("Stack Overflow: Cannot push onto a full stack.");
        }
        arr[++top] = val;
    }

    T pop() {
        if (top < 0) {
            throw std::underflow_error("Stack Underflow: Cannot pop from an empty stack.");
        }
        return arr[top--];
    }

    void display() const {
        if (top < 0) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; --i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        std::cout << "--- Integer Stack ---" << std::endl;
        Stack<int, 5> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.display();
        std::cout << "Popped: " << intStack.pop() << std::endl;
        intStack.display();

        std::cout << "\n--- String Stack ---" << std::endl;
        Stack<std::string, 5> stringStack;
        stringStack.push("Apple");
        stringStack.push("Banana");
        stringStack.push("Cherry");
        stringStack.display();
        std::cout << "Popped: " << stringStack.pop() << std::endl;
        stringStack.display();

    } catch (const std::overflow_error& e) {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    } catch (const std::underflow_error& e) {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}