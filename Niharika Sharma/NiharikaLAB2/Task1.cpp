#include<iostream>
using namespace std;
int main()
{
	float sales[7],total=0,avg;
	int i;
	cout << "Enter the sales of a week: " << endl;
	for(i=0;i<7;i++)
	{
		cout << "Day " << i+1 << "= ";
		cin >> sales[i];
	}
	for(i=0;i<7;i++)
	{
		total=total+sales[i];
	}
	avg=total/7;
	cout << "\nTotal sales = " << total << endl;
	cout << "Average sales = " << avg << endl;
	return 0;
}
