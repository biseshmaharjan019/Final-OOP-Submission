#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException {
public:
    string message() {
        return "Error: Division by zero is not allowed.";
    }
};

class NegativeDenominatorException {
public:
    string message() {
        return "Error: Denominator cannot be negative.";
    }
};

int main() {
    int num, den;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;
    
    try {
        if (den == 0) {
            throw DivideByZeroException();
        }
        if (den < 0) {
            throw NegativeDenominatorException();
        }
        if (num == 999) {
            throw 404;
        }
        
        double result = (double)num / den;
        cout << "Result: " << result << endl;
    }
    catch (DivideByZeroException e) {
        cout << e.message() << endl;
    }
    catch (NegativeDenominatorException e) {
        cout << e.message() << endl;
    }
    catch (...) {
        cout << "Error: An unexpected error occurred." << endl;
    }
    
    return 0;
}
