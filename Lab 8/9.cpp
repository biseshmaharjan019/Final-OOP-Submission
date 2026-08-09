#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Account {
public:
    int accountNumber;
    char lastName[30];
    char firstName[30];
    double totalBalance;

    Account() : accountNumber(0), totalBalance(0.0) {
        lastName[0] = '\0';
        firstName[0] = '\0';
    }

    void getData() {
        cout << "Enter Account Number (1-100): ";
        cin >> accountNumber;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Total Balance: ";
        cin >> totalBalance;
    }

    void showData() const {
        if (accountNumber != 0) {
            cout << "Acc No: " << accountNumber 
                 << " | Name: " << firstName << " " << lastName 
                 << " | Balance: " << totalBalance << endl;
        }
    }
};

int main() {
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        file.open("accounts.dat", ios::out | ios::binary);
        Account blankAcc;
        for (int i = 0; i < 100; i++) {
            file.write(reinterpret_cast<char*>(&blankAcc), sizeof(blankAcc));
        }
        file.close();
        file.open("accounts.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    Account acc;

    do {
        cout << "\n1. Add Account\n2. Display Account\n3. Display All Accounts\n4. Update Account\n5. Delete Account\n6. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            acc.getData();
            file.seekp((acc.accountNumber - 1) * sizeof(Account), ios::beg);
            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));
            cout << "Account added successfully." << endl;
        } 
        else if (choice == 2) {
            int accNum;
            cout << "Enter Account Number to display: ";
            cin >> accNum;
            file.seekg((accNum - 1) * sizeof(Account), ios::beg);
            file.read(reinterpret_cast<char*>(&acc), sizeof(acc));
            if (acc.accountNumber != 0) {
                acc.showData();
            } else {
                cout << "Account does not exist." << endl;
            }
        } 
        else if (choice == 3) {
            file.seekg(0, ios::beg);
            while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
                acc.showData();
            }
            file.clear();
        }
        else if (choice == 4) {
            int accNum;
            cout << "Enter Account Number to update: ";
            cin >> accNum;
            file.seekg((accNum - 1) * sizeof(Account), ios::beg);
            file.read(reinterpret_cast<char*>(&acc), sizeof(acc));
            if (acc.accountNumber != 0) {
                cout << "Existing Record: " << endl;
                acc.showData();
                cout << "Enter New Details:" << endl;
                cout << "Enter First Name: ";
                cin >> acc.firstName;
                cout << "Enter Last Name: ";
                cin >> acc.lastName;
                cout << "Enter Total Balance: ";
                cin >> acc.totalBalance;

                file.seekp((accNum - 1) * sizeof(Account), ios::beg);
                file.write(reinterpret_cast<char*>(&acc), sizeof(acc));
                cout << "Account updated successfully." << endl;
            } else {
                cout << "Account does not exist." << endl;
            }
        }
        else if (choice == 5) {
            int accNum;
            cout << "Enter Account Number to delete: ";
            cin >> accNum;
            file.seekg((accNum - 1) * sizeof(Account), ios::beg);
            file.read(reinterpret_cast<char*>(&acc), sizeof(acc));
            if (acc.accountNumber != 0) {
                Account blankAcc;
                file.seekp((accNum - 1) * sizeof(Account), ios::beg);
                file.write(reinterpret_cast<char*>(&blankAcc), sizeof(blankAcc));
                cout << "Account deleted successfully." << endl;
            } else {
                cout << "Account does not exist." << endl;
            }
        }
    } while (choice != 6);

    file.close();
    return 0;
}