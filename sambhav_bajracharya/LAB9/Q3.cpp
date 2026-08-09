#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException {
public:
    string message() const {
        return "Error: Division by zero is undefined.";
    }
};

class NegativeDenominatorException {
public:
    string message() const {
        return "Error: Denominator cannot be negative.";
    }
};

void performDivision(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivideByZeroException();
    }
    if (denominator < 0) {
        throw NegativeDenominatorException();
    }
    if (numerator == 999) {
        throw 999;
    }

    cout << "Result: " << (float)numerator / denominator << endl;
}

int main() {
    int testCases[4][2] = {
        {10, 2},
        {10, 0},
        {10, -5},
        {999, 5}
    };

    for (int i = 0; i < 4; i++) {
        int num = testCases[i][0];
        int den = testCases[i][1];

        cout << "\nDividing " << num << " by " << den << ":" << endl;
        try {
            performDivision(num, den);
        } catch (const DivideByZeroException& e) {
            cout << e.message() << endl;
        } catch (const NegativeDenominatorException& e) {
            cout << e.message() << endl;
        } catch (...) {
            cout << "Error: An unexpected exception occurred." << endl;
        }
    }

    return 0;
}
