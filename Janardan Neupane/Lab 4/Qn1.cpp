/*
Question 1:
Write a program with a class ATM having private members ownerName and balance,
and static members totalTransactions (int) and totalMoneyMoved (float).
Every call to deposit() and withdraw() should update both static members.
Write a static function showStats() that displays combined transaction data across all objects.
*/

#include <iostream>
using namespace std;

class ATM {
private:
    string ownerName;
    float balance;

    static int totalTransactions;
    static float totalMoneyMoved;

public:
    ATM(string name, float bal) {
        ownerName = name;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        totalTransactions++;
        totalMoneyMoved += amount;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            totalTransactions++;
            totalMoneyMoved += amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }

    static void showStats() {
        cout << "Total Transactions: " << totalTransactions << endl;
        cout << "Total Money Moved: " << totalMoneyMoved << endl;
    }
};

int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0;

int main() {
    ATM a1("Aashray", 5000);
    ATM a2("Ram", 3000);

    a1.deposit(1000);
    a1.withdraw(500);

    a2.deposit(2000);
    a2.withdraw(1000);

    a1.display();
    cout << endl;
    a2.display();

    cout << "\nCombined ATM Statistics:" << endl;
    ATM::showStats();

    return 0;
}