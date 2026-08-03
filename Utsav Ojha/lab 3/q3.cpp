
//3. Write a program with a class BankAccount having private members accountNumber (int), holderName (string), and balance (float). 
//Write a default constructor, a parameterised constructor, and a destructor. 
//Include member functions deposit(float), withdraw(float), and display(). 
//Demonstrate both constructors and the destructor in main. [8]
#include <iostream>
#include <string>
using namespace std;
class Bank {
private:
    int accNo;
    string name;
    float bal;

public:

    // Default constructor
    Bank() {
        accNo = 0;
        name = "Unknown";
        bal = 0;

        cout << "Default constructor called\n";
    }

    // Parameterized constructor
    Bank(int a, string n, float b) {
        accNo = a;
        name = n;
        bal = b;

        cout << "Account created for " << name << endl;
    }

    // Destructor
    ~Bank() {
        cout << "Account of " << name << " closed\n";
    }

    // Deposit function
    void deposit(float amt) {
        if (amt <= 0) {
            cout << "Invalid amount\n";
            return;
        }

        bal = bal + amt;

        cout << "Rs." << amt << " deposited\n";
        cout << "Current Balance = Rs." << bal << endl;
    }

    // Withdraw function
    void withdraw(float amt) {
        if (amt > bal) {
            cout << "Insufficient balance\n";
            return;
        }

        bal = bal - amt;

        cout << "Rs." << amt << " withdrawn\n";
        cout << "Current Balance = Rs." << bal << endl;
    }

    // Display function
    void show() {
        cout << "\nAccount Number : " << accNo << endl;
        cout << "Holder Name   : " << name << endl;
        cout << "Balance       : Rs." << bal << endl;
    }
};

int main() {

    cout << "\n--- Default Object ---\n";

    Bank b1;
    b1.show();

    cout << "\n--- Parameterized Object ---\n";

    Bank b2(101, "Raman", 5000);

    b2.show();

    cout << "\n--- Transactions ---\n";

    b2.deposit(2000);

    b2.withdraw(1500);

    b2.withdraw(9000);

    cout << "\nProgram Ended\n";

    return 0;
}