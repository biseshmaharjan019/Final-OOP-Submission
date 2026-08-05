#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    string ownerName;
    float balance;

    static int totalTransactions;
    static float totalMoneyMoved;

public:
    ATM(string name, float initialBalance) {
        ownerName = name;
        balance = initialBalance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            totalTransactions++;
            totalMoneyMoved += amount;
            cout << ownerName << " deposited $" << amount << endl;
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            totalTransactions++;
            totalMoneyMoved += amount;
            cout << ownerName << " withdrew $" << amount << endl;
        } else {
            cout << "Transaction failed for " << ownerName << ". Insufficient funds." << endl;
        }
    }

    static void showStats() {
        cout << "\nOverall ATM Statistics" << endl;
        cout << "Total Transactions: " << totalTransactions << endl;
        cout << "Total Money Moved: $" << totalMoneyMoved << endl;
    }
};

int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0.0f;

int main() {
    ATM user1("Alice", 1200.0f);
    ATM user2("Bob", 800.0f);

    user1.deposit(300.0f);
    user2.withdraw(150.0f);
    user1.withdraw(200.0f);

    ATM::showStats();

    return 0;
}
