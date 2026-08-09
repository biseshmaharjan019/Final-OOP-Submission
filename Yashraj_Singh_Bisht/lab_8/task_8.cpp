#include <iostream>
#include <fstream>
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
        cout << "\n1. Add Account\n2. Display All Accounts\n3. Exit\nChoice: ";
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
                cout << "Account: " << acc.accountNumber 
                     << " | Name: " << acc.firstName << " " << acc.lastName 
                     << " | Balance: $" << acc.totalBalance << endl;
            }
            file.close();
        }
    } while (choice != 3);
    
    return 0;
}
