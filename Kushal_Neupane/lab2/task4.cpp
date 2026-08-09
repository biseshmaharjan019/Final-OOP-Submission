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

    cout << "Enter item name : ";
    cin >> i.name;
    cout << "Enter item price: ";
    cin >> i.price;

    cout << "\nTotal Bill: " << calculateBill(i) << endl;

    return 0;
}