#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Account {
public:
    int accountNumber;
    char lastName[15];
    char firstName[15];
    float totalBalance;

    void input() {
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Balance: ";
        cin >> totalBalance;
    }

    void display() const {
        if (accountNumber != 0) {
            cout << "Acc #: " << accountNumber 
                 << " | Name: " << firstName << " " << lastName 
                 << " | Balance: $" << totalBalance << endl;
        }
    }
};

void updateAccount() {
    fstream file("bank.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File error!" << endl;
        return;
    }

    int accNum;
    cout << "Enter Account Number to update (1-100): ";
    cin >> accNum;

    file.seekg((accNum - 1) * sizeof(Account));
    Account acc;
    file.read(reinterpret_cast<char*>(&acc), sizeof(Account));

    if (acc.accountNumber == 0) {
        cout << "Account does not exist." << endl;
    } else {
        cout << "Current record details:" << endl;
        acc.display();
        
        cout << "\nEnter updated details:" << endl;
        acc.input();
        acc.accountNumber = accNum;

        file.seekp((accNum - 1) * sizeof(Account));
        file.write(reinterpret_cast<char*>(&acc), sizeof(Account));
        cout << "Account " << accNum << " updated successfully." << endl;
    }
    file.close();
}

void deleteAccount() {
    fstream file("bank.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File error!" << endl;
        return;
    }

    int accNum;
    cout << "Enter Account Number to delete (1-100): ";
    cin >> accNum;

    file.seekg((accNum - 1) * sizeof(Account));
    Account acc;
    file.read(reinterpret_cast<char*>(&acc), sizeof(Account));

    if (acc.accountNumber == 0) {
        cout << "Account does not exist." << endl;
    } else {
        Account blank = {0, "", "", 0.0f};
        file.seekp((accNum - 1) * sizeof(Account));
        file.write(reinterpret_cast<char*>(&blank), sizeof(Account));
        cout << "Account " << accNum << " deleted successfully." << endl;
    }
    file.close();
}

void displayAccounts() {
    ifstream inFile("bank.dat", ios::binary);
    if (!inFile) {
        cout << "No bank file found." << endl;
        return;
    }

    Account acc;
    cout << "\n--- Active Accounts ---" << endl;
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.accountNumber != 0) {
            acc.display();
        }
    }
    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Random Access File Operations ---" << endl;
        cout << "1. Display All Accounts" << endl;
        cout << "2. Update Account" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAccounts();
                break;
            case 2:
                updateAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
