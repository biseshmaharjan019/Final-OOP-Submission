#include <iostream>
using namespace std;

int main() {
    int seats[10] = {0}; 
    int seatNo;

    cout << "Enter seat number to book (1-10): ";
    cin >> seatNo;

    if (seats[seatNo - 1] == 1) {
        cout << "Already booked!" << endl;
    } else {
        seats[seatNo - 1] = 1;
        cout << "Seat booked!" << endl;
    }

    cout << "\nSeat Status" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": ";
        if (seats[i] == 0)
            cout << "Available" << endl;
        else
            cout << "Booked" << endl;
    }

    return 0;
}