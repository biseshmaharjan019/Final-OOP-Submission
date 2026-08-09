// Assignment 2: Define a structure Product with fields name, code, price, and quantity.
// Input details of 5 products and display products with quantity less than 10.

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
    Product products[5];

    cout << "Enter details of 5 products:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << endl;

        cout << "Enter product name: ";
        cin >> ws;
        getline(cin, products[i].name);

        cout << "Enter product code: ";
        cin >> products[i].code;

        cout << "Enter price: ";
        cin >> products[i].price;

        cout << "Enter quantity: ";
        cin >> products[i].quantity;
    }

    cout << "\nProducts with quantity less than 10:" << endl;

    for (int i = 0; i < 5; i++) {
        if (products[i].quantity < 10) {
            cout << "\nProduct Name: " << products[i].name << endl;
            cout << "Code: " << products[i].code << endl;
            cout << "Price: " << products[i].price << endl;
            cout << "Quantity: " << products[i].quantity << endl;
        }
    }

    return 0;
}