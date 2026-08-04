#include <iostream>
using namespace std;

struct Item
{
    string name;
    float price;
};

float calculateBill(Item i)
{
    return i.price + (0.10 * i.price);
}

int main()
{
    Item item;

    cout << "Enter Item Name: ";
    cin >> item.name;

    cout << "Enter Price: ";
    cin >> item.price;

    cout << "\nItem Name: " << item.name << endl;
    cout << "Price: " << item.price << endl;
    cout << "Total Bill (10% Tax): "
         << calculateBill(item);

    return 0;
}
