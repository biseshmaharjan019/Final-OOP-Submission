#include <iostream>
#include <string>

class BankAccount {
private:
    int accountNumber;
    std::string holderName;
    float balance;

public:
    // Default constructor
    BankAccount() {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0.0f;
        std::cout << "[Default Constructor]: Account initialised with default values." << std::endl;
    }

    // Parameterised constructor
    BankAccount(int accNo, std::string name, float initialBalance) {
        accountNumber = accNo;
        holderName = name;
        balance = initialBalance;
        std::cout << "[Parameterised Constructor]: Account created for " << holderName << std::endl;
    }

    // Destructor
    ~BankAccount() {
        std::cout << "[Destructor]: Account " << accountNumber << " closed / went out of scope." << std::endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: RS" << amount << " | New Balance: RS" << balance << std::endl;
        }
    }

    void withdraw(float amount) {
        if (amount > balance) {
            std::cout << "Error: Insufficient balance to withdraw RS" << amount << std::endl;
        } else if (amount > 0) {
            balance -= amount;
            std::cout << "Withdrew: RS" << amount << " | New Balance: RS" << balance << std::endl;
        }
    }

    void display() const {
        std::cout << "Acc No: " << accountNumber << " | Holder: " << holderName 
                  << " | Balance: RS" << balance << std::endl;
    }
};

int main() {
    std::cout << "--- Testing Default Constructor ---" << std::endl;
    BankAccount acc1;
    acc1.display();

    std::cout << "\n--- Testing Parameterised Constructor ---" << std::endl;
    BankAccount acc2(101, "Rajesh", 500.0f);
    acc2.display();

    std::cout << "\n--- Performing Operations ---" << std::endl;
    acc2.deposit(150.50f);
    acc2.withdraw(100.0f);
    acc2.withdraw(600.0f); // Should trigger insufficient balance error

    std::cout << "\n--- Exiting Scope ---" << std::endl;
    return 0;
}