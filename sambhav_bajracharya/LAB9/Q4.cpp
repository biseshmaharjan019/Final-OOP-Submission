#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException {
public:
    string message() const {
        return "Error: Cannot divide by zero.";
    }
};

void compute(int a, int b) {
    try {
        if (b == 0) {
            throw DivideByZeroException();
        }
        cout << "Compute Result: " << (float)a / b << endl;
    } catch (const DivideByZeroException& e) {
        cout << "[compute()] Local catch block: " << e.message() << endl;
        cout << "[compute()] Re-throwing exception to caller..." << endl;
        throw;
    }
}

int main() {
    cout << "Case 1: Valid Inputs (10, 2)" << endl;
    try {
        compute(10, 2);
    } catch (const DivideByZeroException& e) {
        cout << "[main()] Caught re-thrown exception: " << e.message() << endl;
    }

    cout << "\nCase 2: Division by Zero (10, 0)" << endl;
    try {
        compute(10, 0);
    } catch (const DivideByZeroException& e) {
        cout << "[main()] Outer catch block: " << e.message() << endl;
    }

    return 0;
}
