#include <iostream>
#include <string>
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

    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, item.name);

    cout << "Enter item price: ";
    cin >> item.price;

    cout << "\nItem: " << item.name << endl;
    cout << "Total bill with 10% tax = " << calculateBill(item) << endl;
system("pause");
    return 0;
}
