#include <iostream>
using namespace std;

void compute(int a, int b) {
    try {
        if (b == 0) {
            throw "Divide by zero condition detected.";
        }
        cout << "Result of division: " << a / b << endl;
    }
    catch (const char* msg) {
        cout << "Inside compute(): Caught exception locally -> " << msg << endl;
        cout << "Inside compute(): Re-throwing exception to caller..." << endl;
        throw;
    }
}

int main() {
    cout << "--- Successful execution ---" << endl;
    try {
        compute(20, 4);
    }
    catch (const char* msg) {
        cout << "Inside main(): Caught re-thrown exception -> " << msg << endl;
    }

    cout << "\n--- Exception re-throwing execution ---" << endl;
    try {
        compute(20, 0);
    }
    catch (const char* msg) {
        cout << "Inside main(): Caught re-thrown exception -> " << msg << endl;
    }

    return 0;
}