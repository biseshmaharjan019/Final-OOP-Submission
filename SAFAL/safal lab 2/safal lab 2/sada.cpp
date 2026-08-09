#include <iostream>
using namespace std;
int main() {
    int seats[10] = {0};
    int seatNumber;
    cout << "Initial Seat Status:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": ";
        if (seats[i] == 0)
            cout << "Available\n";
        else
            cout << "Booked\n";
    }
    cout << "\nEnter seat number to book (1-10): ";
    cin >> seatNumber;

    if (seatNumber < 1 || seatNumber > 10) {
        cout << "Invalid seat number!\n";
    }
    else if (seats[seatNumber - 1] == 1) {
        cout << "Seat already booked!\n";
    }
    else {
        seats[seatNumber - 1] = 1;
        cout << "Seat booked successfully!\n";
    }
    cout << "\nUpdated Seat Status:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": ";
        if (seats[i] == 0)
            cout << "Available\n";
        else
            cout << "Booked\n";
    }
    return 0;
}
