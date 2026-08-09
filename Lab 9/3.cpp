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

void divide(int num, int den) {
    if (den == 0) {
        throw DivideByZeroException();
    }
    if (den < 0) {
        throw NegativeDenominatorException();
    }
    if (num < 0) {
        throw 500;
    }
    cout << "Result: " << static_cast<float>(num) / den << endl;
}

int main() {
    int num, den;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try {
        divide(num, den);
    } 
    catch (const DivideByZeroException& e) {
        cout << e.message() << endl;
    } 
    catch (const NegativeDenominatorException& e) {
        cout << e.message() << endl;
    } 
    catch (...) {
        cout << "Error: An unexpected exception occurred." << endl;
    }

    return 0;
}