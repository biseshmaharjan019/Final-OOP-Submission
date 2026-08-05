#include <iostream>
using namespace std;
int main() {
    int seats[10] = {0};
    int seatNo;
cout << "Seat Status:\n";
    for(int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": " << seats[i] << endl;
    }
cout << "Enter seat number to book (1-10): ";
    cin >> seatNo;
if(seatNo >= 1 && seatNo <= 10) {
        if(seats[seatNo - 1] == 0) {
            seats[seatNo - 1] = 1;
        cout << "Seat booked successfully.\n";
        } else {
    cout << "Seat already booked.\n";
        }
    } else {
    cout << "Invalid seat number.\n";
    }
cout << "\nUpdated Seat Status:\n";
    for(int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": " << seats[i] << endl;
    }
return 0;
}
