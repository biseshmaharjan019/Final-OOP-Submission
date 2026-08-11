#include <iostream>
using namespace std;

class DivideByZeroException {
public:
    const char* message() const {
        return "Error: Division by zero is not allowed.";
    }
};

class NegativeDenominatorException {
public:
    const char* message() const {
        return "Error: Denominator cannot be negative.";
    }
};

float divide(float numerator, float denominator) {
    if (denominator == 0)
        throw DivideByZeroException();

    if (denominator < 0)
        throw NegativeDenominatorException();

    return numerator / denominator;
}

int main() {
    float numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        float result = divide(numerator, denominator);
        cout << "Result: " << result << endl;
    }
    catch (const DivideByZeroException& e) {
        cout << e.message() << endl;
    }
    catch (const NegativeDenominatorException& e) {
        cout << e.message() << endl;
    }
    catch (...) {
        cout << "An unexpected exception occurred." << endl;
    }

    system("pause");
    return 0;
}
