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
            cout << "Insufficient balance for " << ownerName << endl;
        }
    }

    void display() {
        cout << ownerName << "'s balance: " << balance << endl;
    }

    static void showStats() {
        cout << "\nTotal transactions: " << totalTransactions << endl;
        cout << "Total money moved: " << totalMoneyMoved << endl;
    }
};

int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0;

int main() {
    ATM a1("HARI", 9000);
    ATM a2("NISHCHAL", 3000);

    a1.deposit(1500);
    a1.withdraw(800);

    a2.deposit(7000);
    a2.withdraw(7000);

    a1.display();
    a2.display();

    ATM::showStats();

    system("pause");
    return 0;
}
