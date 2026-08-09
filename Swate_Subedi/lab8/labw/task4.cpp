#include <iostream>
#include <fstream>
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
        cout << "\n1. Add\n2. Display\n3. Exit\nChoice: ";
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
                cout << a.num << " | " << a.first << " " << a.last
                     << " | $" << a.bal << endl;
            }
            f.close();
        }
    } while (ch != 3);
    
    return 0;
}
