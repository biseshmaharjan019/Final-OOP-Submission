#include <iostream>
#include <string>
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
        cout << "\nEnter details for Product " << i + 1 << ":\n";
        cout << "Name     : "; cin >> p[i].name;
        cout << "Code     : "; cin >> p[i].code;
        cout << "Price    : "; cin >> p[i].price;
        cout << "Quantity : "; cin >> p[i].quantity;
    }

    // Display products with quantity < 10
    cout << "\nProducts with Quantity less than 10:\n";
    cout << "--------------------------------------\n";

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (p[i].quantity < 10) {
            cout << "Name     : " << p[i].name << endl;
            cout << "Code     : " << p[i].code << endl;
            cout << "Price    : " << p[i].price << endl;
            cout << "Quantity : " << p[i].quantity << endl;
            cout << "--------------------------------------\n";
            found = true;
        }
    }

    if (!found)
        cout << "No products with quantity less than 10.\n";

    return 0;
}