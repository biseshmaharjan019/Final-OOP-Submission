// Task 4: Write a function calculateBill(Item i) that takes a structure Item
// with name and price, and returns the total bill with 10% tax.

#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    float price;
};

float calculateBill(Item i) {
    float tax = i.price * 0.10;
    return i.price + tax;
}

int main() {
    Item item;
    float totalBill;

    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, item.name);

    cout << "Enter item price: ";
    cin >> item.price;

    totalBill = calculateBill(item);

    cout << "\nItem Name: " << item.name << endl;
    cout << "Price: " << item.price << endl;
    cout << "Total Bill with 10% tax = " << totalBill << endl;

    return 0;
}