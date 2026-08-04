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
    Item singleItem;

    cout << "Enter item name: ";
    getline(cin, singleItem.name);
    cout << "Enter item price: ";
    cin >> singleItem.price;

    float totalBill = calculateBill(singleItem);

    cout << "\n--- Invoice Details ---" << endl;
    cout << "Item Name: " << singleItem.name << endl;
    cout << "Base Price: " << singleItem.price << endl;
    cout << "Total Bill (including 10% tax): " << totalBill << endl;

    return 0;
}