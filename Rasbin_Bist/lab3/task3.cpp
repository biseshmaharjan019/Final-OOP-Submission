#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    float balance;

public:
    BankAccount() {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0.0f;
        cout << "Account created with default values.\n";
    }

    BankAccount(int accNum, string name, float bal) {
        accountNumber = accNum;
        holderName = name;
        balance = bal;
        cout << "Account for " << holderName << " created.\n";
    }

    ~BankAccount() {
        cout << "Account " << accountNumber
             << " (" << holderName << ") is being destroyed.\n";
    }

    void deposit(float amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        cout << "Deposited Rs." << amount << " | New Balance: Rs." << balance << "\n";
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance! Available: Rs." << balance << "\n";
        } else {
            balance -= amount;
            cout << "Withdrawn Rs." << amount << " | New Balance: Rs." << balance << "\n";
        }
    }

    void display() {
        cout << "\nAccount Details\n";
        cout << "Account Number : " << accountNumber << "\n";
        cout << "Holder Name    : " << holderName << "\n";
        cout << "Balance        : Rs." << balance << "\n";
        
    }
};

int main() {
    cout << "=== Demonstrating Default Constructor ===\n";
    BankAccount acc1;
    acc1.deposit(5000);
    acc1.withdraw(1500);
    acc1.display();

    cout << "\n=== Demonstrating Parameterised Constructor ===\n";
    BankAccount acc2(1001, "Ram Sharma", 10000.0f);
    acc2.deposit(2500);
    acc2.withdraw(15000);  
    acc2.withdraw(3000);
    acc2.display();

    cout << "\nEnd of main - destructors will now be called \n";

    return 0;
}