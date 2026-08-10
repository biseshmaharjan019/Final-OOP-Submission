// Bank Account

#include <iostream>
#include <cstdlib>
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
        cout << "Default Constructor Called" << endl;
    }

    BankAccount(int a, string h, float b)
    {
        accountNumber = a;
        holderName = h;
        balance = b;
        cout << "Parameterized Constructor Called" << endl;
    }

    void deposit(float amt)
    {
        balance += amt;
    }

    void withdraw(float amt)
    {
        balance -= amt;
    }

    void display()
    {
        cout << accountNumber << endl;
        cout << holderName << endl;
        cout << balance << endl;
    }

    ~BankAccount()
    {
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    BankAccount a1;
    BankAccount a2(101, "Ram", 5000);

    a2.deposit(1000);
    a2.withdraw(500);

    a2.display();

    system("pause");
    return 0;
}