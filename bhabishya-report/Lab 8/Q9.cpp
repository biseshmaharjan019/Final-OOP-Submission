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
        cout << "\nAccount Number: " << account.accountNumber << endl;
        cout << "Last Name: " << account.lastName << endl;
        cout << "First Name: " << account.firstName << endl;
        cout << "Balance: " << account.balance << endl;
    } else {
        cout << "Account not found." << endl;
    }

    file.close();
}

void updateAccount() {
    int accountNumber;

    cout << "Enter account number to update: ";
    cin >> accountNumber;

    fstream file("accounts.dat", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "File not found." << endl;
        return;
    }

    file.seekg((accountNumber - 1) * sizeof(Account));

    Account account;
    file.read((char*)&account, sizeof(Account));

    if (!file || account.accountNumber != accountNumber) {
        cout << "Account not found." << endl;
        file.close();
        return;
    }

    cout << "Enter new last name: ";
    cin >> setw(30) >> account.lastName;

    cout << "Enter new first name: ";
    cin >> setw(30) >> account.firstName;

    cout << "Enter new balance: ";
    cin >> account.balance;

    file.seekp((accountNumber - 1) * sizeof(Account));
    file.write((char*)&account, sizeof(Account));

    file.close();

    cout << "Account updated successfully." << endl;
}

void deleteAccount() {
    int accountNumber;

    cout << "Enter account number to delete: ";
    cin >> accountNumber;

    fstream file("accounts.dat", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "File not found." << endl;
        return;
    }

    file.seekg((accountNumber - 1) * sizeof(Account));

    Account account;
    file.read((char*)&account, sizeof(Account));

    if (!file || account.accountNumber != accountNumber) {
        cout << "Account not found." << endl;
        file.close();
        return;
    }

    /*
    Mark the record as deleted by setting accountNumber to 0.
    The physical record remains in the random-access file, but it
    is considered an unused/deleted record.
    */
    account.accountNumber = 0;
    account.lastName[0] = '\0';
    account.firstName[0] = '\0';
    account.balance = 0;

    file.seekp((accountNumber - 1) * sizeof(Account));
    file.write((char*)&account, sizeof(Account));

    file.close();

    cout << "Account deleted successfully." << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== BANK ACCOUNT SYSTEM =====" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Display Account" << endl;
        cout << "3. Update Account" << endl;
        cout << "4. Delete Account" << endl;
        cout << "5. Exit" << endl;
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
            updateAccount();
            break;
        case 4:
            deleteAccount();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    system("pause");
    return 0;
}
