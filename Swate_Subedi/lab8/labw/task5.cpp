#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class A {
public:
    int num;
    char last[50];
    char first[50];
    double bal;
};

int main() {
    int ch;
    do {
        cout << "\n1. Add\n2. Display\n3. Update\n4. Delete\n5. Exit\nChoice: ";
        cin >> ch;
        
        if (ch == 1) {
            ofstream f("accounts.dat", ios::binary | ios::app);
            A a;
            cout << "Account: "; cin >> a.num;
            cout << "First: "; cin >> a.first;
            cout << "Last: "; cin >> a.last;
            cout << "Balance: "; cin >> a.bal;
            f.write((char*)&a, sizeof(A));
            f.close();
        }
        else if (ch == 2) {
            ifstream f("accounts.dat", ios::binary);
            A a;
            cout << "\n--- Records ---\n";
            while (f.read((char*)&a, sizeof(A))) {
                if (a.num != 0) {
                    cout << a.num << " | " << a.first << " " << a.last
                         << " | $" << a.bal << endl;
                }
            }
            f.close();
        }
        else if (ch == 3) {
            fstream f("accounts.dat", ios::in | ios::out | ios::binary);
            int target;
            cout << "Account: ";
            cin >> target;
            A a;
            bool found = false;
            while (f.read((char*)&a, sizeof(A))) {
                if (a.num == target) {
                    cout << "New balance: ";
                    cin >> a.bal;
                    int pos = (int)f.tellg() - sizeof(A);
                    f.seekp(pos);
                    f.write((char*)&a, sizeof(A));
                    found = true;
                    cout << "Updated\n";
                    break;
                }
            }
            if (!found) cout << "Not found\n";
            f.close();
        }
        else if (ch == 4) {
            fstream f("accounts.dat", ios::in | ios::out | ios::binary);
            int target;
            cout << "Account: ";
            cin >> target;
            A a;
            bool found = false;
            while (f.read((char*)&a, sizeof(A))) {
                if (a.num == target) {
                    a.num = 0;
                    strcpy(a.first, "");
                    strcpy(a.last, "");
                    a.bal = 0.0;
                    int pos = (int)f.tellg() - sizeof(A);
                    f.seekp(pos);
                    f.write((char*)&a, sizeof(A));
                    found = true;
                    cout << "Deleted\n";
                    break;
                }
            }
            if (!found) cout << "Not found\n";
            f.close();
        }
    } while (ch != 5);
    
    return 0;
}
