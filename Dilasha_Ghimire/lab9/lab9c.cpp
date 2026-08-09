#include <iostream>
#include <string>

class DivideByZeroException {
public:
    std::string message() const {
        return "Error: Division by zero is not allowed!";
    }
};

class NegativeDenominatorException {
public:
    std::string message() const {
        return "Error: Negative denominator is not allowed!";
    }
};

double performDivision(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivideByZeroException();
    }
    if (denominator < 0) {
        throw NegativeDenominatorException();
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num, den;
    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> den;

    try {
        double result = performDivision(num, den);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const DivideByZeroException& e) {
        std::cout << e.message() << std::endl;
    }
    catch (const NegativeDenominatorException& e) {
        std::cout << e.message() << std::endl;
    }
    catch (...) {
        std::cout << "Error: An unexpected exception occurred!" << std::endl;
    }

    return 0;
}