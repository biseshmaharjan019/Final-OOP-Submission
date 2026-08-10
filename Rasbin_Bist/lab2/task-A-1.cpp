#include <iostream>
using namespace std;


void displaySeats(int seats[], int size) {
    cout << "\nSeat Status:\n";
    for (int i = 0; i < size; i++) {
        cout << "Seat " << i + 1 << " : " << (seats[i] == 0 ? "Available" : "Booked") << endl;
    }
}

void bookSeat(int seats[], int size) {
    int seatNum;
    cout << "Enter seat number to book (1-" << size << "): ";
    cin >> seatNum;

    if (seatNum < 1 || seatNum > size) {
        cout << "Invalid seat number.\n";
    } else if (seats[seatNum - 1] == 1) {
        cout << "Seat " << seatNum << " is already booked.\n";
    } else {
        seats[seatNum - 1] = 1;
        cout << "Seat " << seatNum << " booked successfully.\n";
    }
}

int main() {
    int seats[10] = {0};
    int choice;

    do {
        cout << "\n1. Display Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            displaySeats(seats, 10);
        else if (choice == 2) {
            bookSeat(seats, 10);
            displaySeats(seats, 10);
        } else if (choice == 3)
            cout << "Exiting...\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 3);

    return 0;
}