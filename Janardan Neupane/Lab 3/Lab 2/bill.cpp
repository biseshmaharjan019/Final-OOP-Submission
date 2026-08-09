#include <iostream>
using namespace std;
struct Item
{
    char name[20];
    float price;
};
float calculateBill(Item i)
{
    return i.price + (0.10 * i.price);
}

int main()
{
    Item i;
    float totalBill;
    cout << "Enter item name: ";
    cin >> i.name;
    cout << "Enter item price: ";
    cin >> i.price;
    totalBill = calculateBill(i);
    cout << "\nItem Name : " << i.name << endl;
    cout << "Item Price : " << i.price << endl;
    cout << "Total Bill with 10% tax = " << totalBill << endl;
  return 0;
}