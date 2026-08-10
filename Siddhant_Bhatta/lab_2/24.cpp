#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    float  price;
};

float calculateBill(Item i) {
    float tax      = i.price * 0.10;
    float totalBill = i.price + tax;
    return totalBill;
}

int main() {
    Item item;

    cout << "Enter item name  : "; cin >> item.name;
    cout << "Enter item price : "; cin >> item.price;

    float bill = calculateBill(item);

    cout << "\n--- Bill Summary ---\n";
    cout << "Item       : " << item.name          << endl;
    cout << "Price      : $" << item.price        << endl;
    cout << "Tax (10%)  : $" << item.price * 0.10 << endl;
    cout << "Total Bill : $" << bill              << endl;

    return 0;
}