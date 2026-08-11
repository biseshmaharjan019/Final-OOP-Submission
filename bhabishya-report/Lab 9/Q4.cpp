#include <iostream>
using namespace std;

void compute(int a, int b) {
    try {
        if (b == 0)
            throw "Division by zero";

        cout << "Result: " << a / b << endl;
    }
    catch (const char* message) {
        cout << "compute(): Caught exception: "
             << message << endl;

        cout << "compute(): Re-throwing exception to main()..."
             << endl;

        throw;
    }
}

int main() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    try {
        compute(a, b);
    }
    catch (const char* message) {
        cout << "main(): Caught re-thrown exception: "
             << message << endl;
    }

    /*
    If b is zero:
    1. The exception is thrown inside compute().
    2. compute() catches it locally.
    3. compute() prints a message and uses throw; to re-throw it.
    4. main() catches the same exception.
    */

    system("pause");
    return 0;
}
