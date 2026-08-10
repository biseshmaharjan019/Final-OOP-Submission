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
        cout << "Enter Account Number (1-100): ";
        cin >> accountNumber;
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

void addAccount() {
    fstream file("bank.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        ofstream create("bank.dat", ios::binary);
        Account blank = {0, "", "", 0.0f};
        for (int i = 0; i < 100; i++) {
            create.write(reinterpret_cast<char*>(&blank), sizeof(Account));
        }
        create.close();
        file.open("bank.dat", ios::binary | ios::in | ios::out);
    }

    Account acc;
    acc.input();

    file.seekp((acc.accountNumber - 1) * sizeof(Account));
    file.write(reinterpret_cast<char*>(&acc), sizeof(Account));
    file.close();

    cout << "Account saved at record position " << acc.accountNumber << endl;
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
        cout << "\n1. Add Account\n2. Display All Accounts\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            addAccount();
        } else if (choice == 2) {
            displayAccounts();
        }
    } while (choice != 3);

    return 0;
}
