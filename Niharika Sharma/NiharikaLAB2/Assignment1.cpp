#include<iostream>
using namespace std;
int  main()
{
	int seats[10]={0};
	int seatNo,i;
	cout << "Seat status:\n";
	for(i=0;i<10;i++)
	{
		cout << "Seat" << i+1 << ": " << seats[i] <<endl;	
	}
	cout << "\nEnter seat number to book (1-10): ";
	cin >> seatNo;
	if(seatNo<1 || seatNo>10)
	{
		cout << "Invalid seat number!" <<endl;
	}
	else if(seats[seatNo-1]==1)
	{
		cout << "Seat already booked!" <<endl;
	}
	else
	{
		seats[seatNo-1]=1;
		cout << "Seat booked successfully!" <<endl;
	}
	cout << "\nUpdated seat status: \n";
	for(i=0;i<10;i++)
	{
		cout << "Seat " << i+1 << ": ";
		if(seats[i]==0)
		{
			cout << "Available";
		}
		else
		{
        	cout << "Booked";
        }
        cout << endl;
	}
	return 0;
}
