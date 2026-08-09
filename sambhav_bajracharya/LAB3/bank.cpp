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
        cout << "Default Constructor called." << endl;
    }

    BankAccount(int accNum, string name, float bal) {
        accountNumber = accNum;
        holderName = name;
        balance = bal;
        cout << "Parameterized Constructor called for " << holderName << "." << endl;
    }

    ~BankAccount() {
        cout << "Destructor called for account " << accountNumber << "." << endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        }
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else if (amount > 0) {
            balance -= amount;
            cout << "Withdrew: " << amount << ". Remaining Balance: " << balance << endl;
        }
    }

    void display() {
        cout << " Account Details " << endl;
        cout << "Acc Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    {
        BankAccount acc1;
        acc1.display();
    }

    cout << endl;

    BankAccount acc2(101, "Ram", 500.50f);
    acc2.display();

    acc2.deposit(150.0f);
    acc2.withdraw(100.0f);
    acc2.display();

    return 0;
}
