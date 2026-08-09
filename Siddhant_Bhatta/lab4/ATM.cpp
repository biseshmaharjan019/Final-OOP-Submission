// WAP a program with a class ATM having private members ownerName and balance, and
// static members Total transaction (int) and total money moved (float). Every call to deposit
// and withdraw should update both static members. Write a static function to display combined
//  transaction data across all objects. Demonstrate with two ATM objects.
#include <iostream>
#include <string>
using namespace std;

class ATM
{
private:
    std::string ownerName;
    float balance;

public:
    ATM(const std::string &name, float initialBalance);
    void deposit(float amount);
    void withdraw(float amount);
    float getBalance() const;
    std::string getOwnerName() const;
    static int TotalTransactions;
    static float TotalMoneyMoved;
    static void displayCombinedTransactionData();
};
int main()
{
    ATM atm1("Alice", 1000.0f);
    ATM atm2("Bob", 500.0f);

    atm1.deposit(200.0f);
    atm1.withdraw(150.0f);

    atm2.deposit(300.0f);
    atm2.withdraw(100.0f);

    cout << "ATM 1 - Owner: " << atm1.getOwnerName() << ", Balance: " << atm1.getBalance() << endl;
    cout << "ATM 2 - Owner: " << atm2.getOwnerName() << ", Balance: " << atm2.getBalance() << endl;

    ATM::displayCombinedTransactionData();

    return 0;
}