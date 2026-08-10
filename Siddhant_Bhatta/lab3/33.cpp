#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string holderName;
    float balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0.0;
        cout << "Default constructor invoked" << endl;
    }

    BankAccount(int accNum, string name, float bal)
    {
        accountNumber = accNum;
        holderName = name;
        balance = bal;
        cout << "Parameterized constructor invoked" << endl;
    }

    ~BankAccount()
    {
        cout << "Destructor invoked for account: " << accountNumber << endl;
    }

    void deposit(float amount)
    {
        balance += amount;
        cout << amount << " deposited. New Balance: " << balance << endl;
    }

    void withdraw(float amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << amount << " withdrawn. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display()
    {
        cout << "Acc Num: " << accountNumber << " | Holder: " << holderName
             << " | Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account1;
    account1.display();

    cout << endl;

    BankAccount account2(101, "Alice", 5000.0);
    account2.display();
    account2.deposit(1500.0);
    account2.withdraw(2000.0);

    cout << endl;
    return 0;
}