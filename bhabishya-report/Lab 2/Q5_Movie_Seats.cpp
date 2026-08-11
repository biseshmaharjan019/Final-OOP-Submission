#include <iostream>
using namespace std;

int main() {
    int seats[10] = {0};
    int seatNumber;

    cout << "Seat status (0 = Available, 1 = Booked):\n";
    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": " << seats[i] << endl;
    }

    cout << "\nEnter seat number to book (1-10): ";
    cin >> seatNumber;

    if (seatNumber < 1 || seatNumber > 10) {
        cout << "Invalid seat number." << endl;
    } else if (seats[seatNumber - 1] == 1) {
        cout << "Seat is already booked." << endl;
    } else {
        seats[seatNumber - 1] = 1;
        cout << "Seat booked successfully." << endl;
    }

    cout << "\nUpdated seat status:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": " << seats[i] << endl;
    }
system("pause");
    return 0;
}
