#include <iostream>
using namespace std;

int seats[10] = {0};

void display() {
    for (int i = 0; i < 10; i++)
        cout << "Seat " << i+1 << ": " << (seats[i] ? "BOOKED" : "AVAILABLE") << "\n";
}

int main() {
    int ch, s;
    do {
        cout << "\n1.View  2.Book  3.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) display();
        else if (ch == 2) {
            display();
            cout << "Seat number: "; cin >> s;
            if (s < 1 || s > 10) cout << "Invalid!\n";
            else if (seats[s-1]) cout << "Already booked!\n";
            else { seats[s-1] = 1; cout << "Booked!\n"; }
        }
    } while (ch != 3);
}