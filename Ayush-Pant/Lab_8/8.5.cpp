#include <iostream>
#include <fstream>
using namespace std;

class Account {
public:
    int accNo;
    char lastName[20];
    char firstName[20];
    float balance;
    bool active;
};

void addAccount() {
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);
    Account a;
    cout << "Enter account number, last name, first name, balance: ";
    cin >> a.accNo >> a.lastName >> a.firstName >> a.balance;
    a.active = true;
    file.seekp(a.accNo * sizeof(Account));
    file.write((char*)&a, sizeof(a));
    file.close();
}

void updateAccount() {
    int accNo;
    cout << "Enter account number to update: ";
    cin >> accNo;
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);
    Account a;
    file.seekg(accNo * sizeof(Account));
    file.read((char*)&a, sizeof(a));
    if (a.active) {
        cout << "Enter new balance: ";
        cin >> a.balance;
        file.seekp(accNo * sizeof(Account));
        file.write((char*)&a, sizeof(a));
    } else {
        cout << "Account not found" << endl;
    }
    file.close();
}

void deleteAccount() {
    int accNo;
    cout << "Enter account number to delete: ";
    cin >> accNo;
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);
    Account a;
    file.seekg(accNo * sizeof(Account));
    file.read((char*)&a, sizeof(a));
    a.active = false;
    file.seekp(accNo * sizeof(Account));
    file.write((char*)&a, sizeof(a));
    file.close();
}

void displayAccount() {
    int accNo;
    cout << "Enter account number to display: ";
    cin >> accNo;
    ifstream file("accounts.dat", ios::binary);
    Account a;
    file.seekg(accNo * sizeof(Account));
    file.read((char*)&a, sizeof(a));
    if (a.active)
        cout << a.accNo << " " << a.lastName << " " << a.firstName << " " << a.balance << endl;
    else
        cout << "Account not found" << endl;
    file.close();
}

int main() {
    int choice;
    cout << "1. Add  2. Display  3. Update  4. Delete: ";
    cin >> choice;
    if (choice == 1) addAccount();
    else if (choice == 2) displayAccount();
    else if (choice == 3) updateAccount();
    else if (choice == 4) deleteAccount();
}
