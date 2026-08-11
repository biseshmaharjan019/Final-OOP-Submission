#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Account {
    int accountNumber;
    char lastName[30];
    char firstName[30];
    double balance;
};

void addAccount() {
    Account account;

    cout << "Enter account number: ";
    cin >> account.accountNumber;

    cout << "Enter last name: ";
    cin >> setw(30) >> account.lastName;

    cout << "Enter first name: ";
    cin >> setw(30) >> account.firstName;

    cout << "Enter total balance: ";
    cin >> account.balance;

    fstream file("accounts.dat", ios::in | ios::out | ios::binary);

    if (!file) {
        file.open("accounts.dat", ios::out | ios::binary);
        file.close();
        file.open("accounts.dat", ios::in | ios::out | ios::binary);
    }

    file.seekp((account.accountNumber - 1) * sizeof(Account));
    file.write((char*)&account, sizeof(Account));

    file.close();

    cout << "Account added successfully." << endl;
}

void displayAccount() {
    int accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;

    ifstream file("accounts.dat", ios::binary);

    if (!file) {
        cout << "File not found." << endl;
        return;
    }

    file.seekg((accountNumber - 1) * sizeof(Account));

    Account account;
    file.read((char*)&account, sizeof(Account));

    if (file && account.accountNumber == accountNumber) {
        cout << "\nAccount Information" << endl;
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "Last Name: " << account.lastName << endl;
        cout << "First Name: " << account.firstName << endl;
        cout << "Balance: " << account.balance << endl;
    } else {
        cout << "Account not found." << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== ACCOUNT MANAGEMENT =====" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Display Account" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addAccount();
            break;
        case 2:
            displayAccount();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    system("pause");
    return 0;
}
