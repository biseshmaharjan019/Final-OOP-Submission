#include <iostream>
#include <string>

void compute(int a, int b) {
    try {
        if (b == 0) {
            throw std::string("Division by zero error in compute()");
        }
        std::cout << "Result: " << (a / b) << std::endl;
    }
    catch (const std::string& ex) {
        std::cout << "[Local Catch in compute()]: " << ex << std::endl;
        std::cout << "[compute()]: Re-throwing exception to caller..." << std::endl;
        throw;
    }
}

int main() {
    std::cout << "--- Attempting compute(10, 2) ---" << std::endl;
    try {
        compute(10, 2);
    } 
    catch (const std::string& ex) {
        std::cout << "[Main Catch]: " << ex << std::endl;
    }

    std::cout << "\n--- Attempting compute(10, 0) ---" << std::endl;
    try {
        compute(10, 0);
    } 
    catch (const std::string& ex) {
        std::cout << "[Main Catch]: Handled re-thrown exception -> " << ex << std::endl;
    }

    return 0;
}