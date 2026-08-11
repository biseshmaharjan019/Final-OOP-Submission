#include <iostream>
#include <ctime>
using namespace std;

class BankAccount {
public:
    int accountNumber;
    string holderName;
    float balance;

    BankAccount(int acc, string name) {
        accountNumber = acc;       
        holderName = name;         
        balance = (rand() % 10000) + 1;
        cout << "Account created! Starting balance: " << balance << "\n";
    }

    void deposit(float amount) {
        balance += amount;
        cout << amount << " deposited successfully\n";
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << amount << " withdrawn successfully\n";
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void display() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Holder Name:    " << holderName << endl;
        cout << "Balance:        " << balance << endl;
    }

    ~BankAccount() {
        cout << "\nDestructor called\n";
    }
};

int main() {
    srand(time(0));           

    int acc;
    string name;

    cout << "Enter account number: ";
    cin >> acc;

    cout << "Enter holder name: ";
    cin >> name;

    BankAccount a1(acc, name);   

    a1.display();

    int depoamount;
    cout << "How much do you want to deposit: ";
    cin >> depoamount;
    a1.deposit(depoamount);

    char choice;
    cout << "Do you want to withdraw too? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int witamount;
        cout << "How much do you want to withdraw: ";
        cin >> witamount;
        a1.withdraw(witamount);
    }

    a1.display();

    return 0;
}