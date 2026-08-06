#include<iostream>
using namespace std;
struct Product
{
	string name;
	int code,price,quantity;
};
int main()
{
	Product p[5];
	cout << "Enter product details:\n";
	for(int i=0;i<5;i++)
	{
		cout << "\nProduct " << i+1 <<":\n";
		cout << "Enter name: ";
		cin >> p[i].name;
		cout << "Enter code: ";
		cin >> p[i].code;
		cout << "Enter price: ";
		cin >> p[i].price;
		cout << "Enter quantity: ";
		cin >> p[i].quantity;
	}
	cout << "\nDetails of products with quantity less than 10:\n";
	for(int i=0;i<5;i++)
	{
		if(p[i].quantity<10)
		{
			cout << "\nName: " << p[i].name <<endl;
			cout << "Code: " << p[i].code <<endl;
			cout << "Price: " << p[i].price <<endl;
			cout << "Quantity: " << p[i].quantity <<endl;
		}
	}
	return 0;
}
