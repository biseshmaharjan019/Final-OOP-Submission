#include<iostream>
using namespace std;
float convertCurrency(float amount,float rate)
{
	return amount*rate;
}
int main()
{
	float amount,rate,result;
	cout << "Enter amount : ";
	cin >> amount;
	cout << "Enter rate : ";
	cin >> rate;
	result=convertCurrency(amount,rate);
	cout << "Converted amount = " << result;
	return 0;
}
