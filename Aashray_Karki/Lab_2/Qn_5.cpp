// Assignment 1: Write a program to manage seat availability for a movie theater
// using an array of 10 seats. 1 means booked and 0 means available.
// Allow users to book a seat and display the updated seat status.

#include <iostream>
using namespace std;

int main() {
    int seats[10] = {0};
    int seatNo;

    cout << "Initial Seat Status:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": " << seats[i] << endl;
    }

    cout << "\nEnter seat number to book (1 to 10): ";
    cin >> seatNo;

    if (seatNo < 1 || seatNo > 10) {
        cout << "Invalid seat number." << endl;
    } else if (seats[seatNo - 1] == 1) {
        cout << "Seat already booked." << endl;
    } else {
        seats[seatNo - 1] = 1;
        cout << "Seat booked successfully." << endl;
    }

    cout << "\nUpdated Seat Status:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": " << seats[i] << endl;
    }

    return 0;
}