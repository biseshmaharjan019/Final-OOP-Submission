#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Account {
public:
    int accountNumber;
    char lastName[50];
    char firstName[50];
    double totalBalance;
};

int main() {
    int choice;
    do {
        cout << "\n1. Add Account\n2. Display All\n3. Update Balance\n4. Delete Account\n5. Exit\nChoice: ";
        cin >> choice;
        
        if (choice == 1) {
            ofstream file("accounts.dat", ios::binary | ios::app);
            Account acc;
            cout << "Enter account number: ";
            cin >> acc.accountNumber;
            cout << "Enter first name: ";
            cin >> acc.firstName;
            cout << "Enter last name: ";
            cin >> acc.lastName;
            cout << "Enter total balance: ";
            cin >> acc.totalBalance;
            file.write((char*)&acc, sizeof(Account));
            file.close();
        } 
        else if (choice == 2) {
            ifstream file("accounts.dat", ios::binary);
            Account acc;
            cout << "\n--- Account Records ---" << endl;
            while (file.read((char*)&acc, sizeof(Account))) {
                if (acc.accountNumber != 0) {
                    cout << "Account: " << acc.accountNumber 
                         << " | Name: " << acc.firstName << " " << acc.lastName 
                         << " | Balance: $" << acc.totalBalance << endl;
                }
            }
            file.close();
        } 
        else if (choice == 3) {
            fstream file("accounts.dat", ios::in | ios::out | ios::binary);
            int accNum;
            cout << "Enter account number to update: ";
            cin >> accNum;
            Account acc;
            bool found = false;
            
            while (file.read((char*)&acc, sizeof(Account))) {
                if (acc.accountNumber == accNum) {
                    cout << "Enter new balance: ";
                    cin >> acc.totalBalance;
                    int pos = (int)file.tellg() - sizeof(Account);
                    file.seekp(pos);
                    file.write((char*)&acc, sizeof(Account));
                    found = true;
                    cout << "Record updated." << endl;
                    break;
                }
            }
            if (!found) cout << "Record not found." << endl;
            file.close();
        } 
        else if (choice == 4) {
            fstream file("accounts.dat", ios::in | ios::out | ios::binary);
            int accNum;
            cout << "Enter account number to delete: ";
            cin >> accNum;
            Account acc;
            bool found = false;
            
            while (file.read((char*)&acc, sizeof(Account))) {
                if (acc.accountNumber == accNum) {
                    acc.accountNumber = 0;
                    strcpy(acc.firstName, "");
                    strcpy(acc.lastName, "");
                    acc.totalBalance = 0.0;
                    int pos = (int)file.tellg() - sizeof(Account);
                    file.seekp(pos);
                    file.write((char*)&acc, sizeof(Account));
                    found = true;
                    cout << "Record deleted." << endl;
                    break;
                }
            }
            if (!found) cout << "Record not found." << endl;
            file.close();
        }
    } while (choice != 5);
    
    return 0;
}
