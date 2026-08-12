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
    float bill;
    cout << "Enter item name  : ";
    cin>>item.name;
    cout << "Enter item price : ";
    cin >> item.price;
    bill = calculateBill(item);
    cout << endl;
    cout << "Item  : " << item.name << endl;
    cout << "Price : Rs. " << item.price << endl;
    cout << "Tax   : Rs. " << item.price * 0.10 << endl;
    cout << "Total : Rs. " << bill << endl;

    return 0;
}
