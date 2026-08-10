// Movie Theater Seat Booking

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int seats[10] = {0};
    int seat;

    cout << "Enter seat number to book (1-10): ";
    cin >> seat;

    if(seat >= 1 && seat <= 10 && seats[seat - 1] == 0)
    {
        seats[seat - 1] = 1;
        cout << "Seat booked successfully.\n";
    }
    else
    {
        cout << "Seat not available.\n";
    }

    cout << "\nSeat Status:\n";

    for(int i = 0; i < 10; i++)
    {
        cout << "Seat " << i + 1 << " : " << seats[i] << endl;
    }

    system("pause");
    return 0;
}