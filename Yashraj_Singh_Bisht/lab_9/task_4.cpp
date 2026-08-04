#include <iostream>
using namespace std;

void compute(int a, int b) {
    try {
        if (b == 0) {
            throw "Divide by zero condition detected";
        }
        cout << "Result: " << a / b << endl;
    }
    catch (const char* msg) {
        cout << "Exception handled locally inside compute(): " << msg << endl;
        throw;
    }
}

int main() {
    try {
        cout << "Testing compute(10, 2):" << endl;
        compute(10, 2);
        
        cout << "\nTesting compute(10, 0):" << endl;
        compute(10, 0);
    }
    catch (const char* msg) {
        cout << "Exception handled globally inside main(): " << msg << endl;
    }
    return 0;
}
