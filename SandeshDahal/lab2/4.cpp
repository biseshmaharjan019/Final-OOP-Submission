// iv. Function calculateBill with 10% tax
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
    Item i;

    cout << "Enter item name: ";
    cin >> i.name;

    cout << "Enter price: ";
    cin >> i.price;

    cout << "Total Bill = " << calculateBill(i);

    return 0;
}