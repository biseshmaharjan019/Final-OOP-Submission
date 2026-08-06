#include <iostream>
using namespace std;
class BankAccount
{
int accountNumber;
    string holderName;
    float balance;
public:
    BankAccount()
    {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0;
        cout << "Default Constructor Called\n";
    }

    BankAccount(int a, string h, float b)
    {
        accountNumber = a;
        holderName = h;
        balance = b;
        cout << "Parameterized Constructor Called\n";
    }
void deposit(float amt)
    {
    balance += amt;
    }
void withdraw(float amt)
    {
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient Balance\n";
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }

    ~BankAccount()
    {
        cout << "Destructor Called\n";
    }
};
int main()
{
    BankAccount a1;
    BankAccount a2(101, "Ram", 5000);
a2.deposit(1000);
    a2.withdraw(2000);
a1.display();
    a2.display();
return 0;
}
