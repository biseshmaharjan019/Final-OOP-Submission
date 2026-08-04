#include<iostream>
using namespace std;

class ATM
{
private:
    string ownerName;
    float balance;

    static int totalTransactions;
    static float totalMoneyMoved;

public:
    ATM(string n,float b)
    {
        ownerName=n;
        balance=b;
    }

    void deposit(float amt)
    {
        balance+=amt;
        totalTransactions++;
        totalMoneyMoved+=amt;
    }

    void withdraw(float amt)
    {
        if(balance>=amt)
        {
            balance-=amt;
            totalTransactions++;
            totalMoneyMoved+=amt;
        }
    }

    void display()
    {
        cout<<ownerName<<" Balance = "<<balance<<endl;
    }

    static void showStats()
    {
        cout<<"Total Transactions = "<<totalTransactions<<endl;
        cout<<"Total Money Moved = "<<totalMoneyMoved<<endl;
    }
};

int ATM::totalTransactions=0;
float ATM::totalMoneyMoved=0;

int main()
{
    ATM a1("Ram",5000);
    ATM a2("Shyam",3000);

    a1.deposit(1000);
    a1.withdraw(500);

    a2.deposit(2000);
    a2.withdraw(1000);

    a1.display();
    a2.display();

    ATM::showStats();

    return 0;
}