#include <iostream>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
    int quantity;
};

int main() {
    Product p[5];

    // Input
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for Product " << i + 1 << ":" << endl;
        cout << "  Name    : "; cin >> p[i].name;
        cout << "  Code    : "; cin >> p[i].code;
        cout << "  Price   : "; cin >> p[i].price;
        cout << "  Quantity: "; cin >> p[i].quantity;
        cout << endl;
    }

    // Display products with quantity < 10
    cout << "===== Products with Low Stock (Qty < 10) =====" << endl;
    for (int i = 0; i < 5; i++) {
        if (p[i].quantity < 10) {
            cout << "Name    : " << p[i].name     << endl;
            cout << "Code    : " << p[i].code     << endl;
            cout << "Price   : " << p[i].price    << endl;
            cout << "Quantity: " << p[i].quantity << endl;
            cout << endl;
        }
    }

    return 0;
}