// Q3. Write a program with a class BankAccount having private members
// accountNumber, holderName, and balance. Write a default constructor,
// parameterized constructor, member functions deposit(), withdraw(), display(),
// and a destructor.

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
        cout << "Default constructor called" << endl;
    }

    BankAccount(int acc, string name, float bal) {
        accountNumber = acc;
        holderName = name;
        balance = bal;
        cout << "Parameterized constructor called" << endl;
    }

    void deposit(float amount) {
        balance = balance + amount;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance = balance - amount;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }

    ~BankAccount() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    BankAccount b1;
    BankAccount b2(101, "Ujjwal", 5000);

    b1.display();

    b2.deposit(1000);
    b2.withdraw(1500);
    b2.display();

    return 0;
}