#include<iostream>
#include<string>
using namespace std;
struct Item
{
	string name;
	float price;
};
float calculateBill(Item i)
{
	return i.price+(0.1*i.price);
}
int main()
{
	Item n;
	float bill;
	cout << "Enter item name: ";
	cin >> n.name;
	cout << "Enter item price: ";
	cin >> n.price;
	bill=calculateBill(n);
	cout << "\nItem name: " <<n.name <<endl;
	cout << "Item price: " <<n.price <<endl;
	cout << "Total bill (with 10% tax): " <<bill <<endl;
	return 0;
}
