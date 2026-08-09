#include <iostream>
#include <fstream>
#include <cstring>

class Account {
public:
    int accountNumber;
    char lastName[15];
    char firstName[15];
    double balance;

    Account() {
        accountNumber = 0;
        lastName[0] = '\0';
        firstName[0] = '\0';
        balance = 0.0;
    }
};

int main() {
    std::fstream file("bank.dat", std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
    if (!file) {
        std::ofstream create("bank.dat", std::ios::binary);
        create.close();
        file.open("bank.dat", std::ios::binary | std::ios::in | std::ios::out);
    }

    int choice;
    do {
        std::cout << "\n=== BANK TRANSACTION SYSTEM ===" << std::endl;
        std::cout << "1. Add Account" << std::endl;
        std::cout << "2. Display All Accounts" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            Account acc;
            std::cout << "Enter Account Number: ";
            std::cin >> acc.accountNumber;
            std::cout << "Enter Last Name: ";
            std::cin >> acc.lastName;
            std::cout << "Enter First Name: ";
            std::cin >> acc.firstName;
            std::cout << "Enter Balance: ";
            std::cin >> acc.balance;

            file.seekp((acc.accountNumber - 1) * sizeof(Account));
            file.write(reinterpret_cast<char*>(&acc), sizeof(Account));
            std::cout << "Account saved successfully!" << std::endl;
        } 
        else if (choice == 2) {
            file.clear();
            file.seekg(0, std::ios::beg);
            Account acc;
            std::cout << "\n--- Account Records ---" << std::endl;
            while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
                if (acc.accountNumber != 0) {
                    std::cout << "Acc #: " << acc.accountNumber
                              << " | Name: " << acc.firstName << " " << acc.lastName
                              << " | Balance: $" << acc.balance << std::endl;
                }
            }
        }
    } while (choice != 3);

    file.close();
    return 0;
}