#include <iostream>
#include <fstream>
using namespace std;

class Account {
public:
    int accNo;
    char lastName[20];
    char firstName[20];
    float balance;
};

void addAccount() {
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);
    Account a;
    cout << "Enter account number, last name, first name, balance: ";
    cin >> a.accNo >> a.lastName >> a.firstName >> a.balance;
    file.seekp(a.accNo * sizeof(Account));
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
    cout << a.accNo << " " << a.lastName << " " << a.firstName << " " << a.balance << endl;
    file.close();
}

int main() {
    int choice;
    cout << "1. Add  2. Display: ";
    cin >> choice;
    if (choice == 1) addAccount();
    else displayAccount();
}
