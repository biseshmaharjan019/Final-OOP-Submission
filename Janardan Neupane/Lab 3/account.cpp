#include <iostream>
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
        cout << "Default constructor called\n";
    }
    BankAccount(int acc, string name, float bal) {
        accountNumber = acc;
        holderName = name;
        balance = bal;
        cout << "Parameterized constructor called\n";
    }
    ~BankAccount() {
        cout << "Destructor called for account: " << accountNumber << "\n";
    }

    void deposit(float amt) {
        balance += amt;
    }
    void withdraw(float amt) {
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient balance\n";
    }
    void display() {
        cout << "\nAccount No: " << accountNumber;
        cout << "\nHolder Name: " << holderName;
        cout << "\nBalance: " << balance << endl;
    }
};
int main() {
    BankAccount acc1;
    acc1.deposit(500);
    acc1.display();
    BankAccount acc2(101, "Janardan", 1000);
    acc2.withdraw(200);
    acc2.display();

    return 0;
}