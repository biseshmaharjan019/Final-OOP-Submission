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

int main() {
    fstream file("account.dat", ios::out | ios::binary);

    Account blank = {0, "", "", 0};
    for (int i = 0; i < 10; i++)
        file.write((char*)&blank, sizeof(blank));

    file.close();

    file.open("account.dat", ios::in | ios::out | ios::binary);

    int choice;
    Account a;

    do {
        cout << "\n1.Add\n2.Display\n3.Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Account No LastName FirstName Balance: ";
            cin >> a.accNo >> a.lastName >> a.firstName >> a.balance;
            file.seekp((a.accNo - 1) * sizeof(a));
            file.write((char*)&a, sizeof(a));
        }

        else if (choice == 2) {
            file.seekg(0);
            while (file.read((char*)&a, sizeof(a))) {
                if (a.accNo != 0)
                    cout << a.accNo << " " << a.lastName << " " << a.firstName << " " << a.balance << endl;
            }
        }

    } while (choice != 3);

    file.close();
    return 0;
}