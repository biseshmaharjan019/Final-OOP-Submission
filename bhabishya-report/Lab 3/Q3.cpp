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
        balance = 0;
        cout << "Default constructor called." << endl;
    }

    BankAccount(int accNo, string name, float bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
        cout << "Parameterized constructor called." << endl;
    }

    ~BankAccount() {
        cout << "Destructor called for account " << accountNumber << "." << endl;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance." << endl;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount a1;

    cout << "\nDefault account:" << endl;
    a1.display();

    BankAccount a2(101, "Ram", 5000);

    a2.deposit(2000);
    a2.withdraw(1000);

    cout << "\nParameterized account:" << endl;
    a2.display();

    system("pause");
    return 0;
}
