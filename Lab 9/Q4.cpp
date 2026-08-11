#include <iostream>
using namespace std;

void compute(int a, int b) {
    try {
        if (b == 0) {
            throw "Division by zero error!";
        }
        cout << "Result of " << a << " / " << b << " = " << (a / b) << endl;
    }
    catch (const char* msg) {
        cout << "[compute()] Exception caught locally: " << msg << endl;
        cout << "[compute()] Re-throwing exception to the caller..." << endl;
        throw; // Re-throws the active exception
    }
}

int main() {
    int num1, num2;

    cout << "Enter numerator: ";
    cin >> num1;
    cout << "Enter denominator: ";
    cin >> num2;

    cout << "\n--- Invoking compute() inside main() try-catch block ---" << endl;
    try {
        compute(num1, num2);
    }
    catch (const char* msg) {
        cout << "[main()] Caught re-thrown exception: " << msg << endl;
    }

    cout << "\nProgram execution resumed and completed successfully." << endl;

    cout << "\nPress Enter to close program...";
    cin.ignore();
    cin.get();
    return 0;
}