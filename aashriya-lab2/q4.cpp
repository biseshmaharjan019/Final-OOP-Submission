#include <iostream>
using namespace std;

struct Item {
    string name;
    float price;
};

float calculateBill(Item i) {
    return i.price + (i.price * 0.10);
}

int main() {
    Item item;

    cout << "Enter Item Name: ";
    cin >> item.name;

    cout << "Enter Item Price: ";
    cin >> item.price;

    float totalBill = calculateBill(item);

    cout << "\nItem Name: " << item.name << endl;
    cout << "Price: " << item.price << endl;
    cout << "Total Bill (including 10% tax): " << totalBill << endl;

    return 0;
}