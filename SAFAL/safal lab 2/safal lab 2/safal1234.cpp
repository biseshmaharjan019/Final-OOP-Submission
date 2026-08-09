#include <iostream>
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
    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter item price: ";
    cin >> item.price;
    float totalBill = calculateBill(item);
    cout << "\nItem Name: " << item.name << endl;
    cout << "Original Price: " << item.price << endl;
    cout << "Total Bill (with 10% tax): " << totalBill << endl;
    return 0;
}
