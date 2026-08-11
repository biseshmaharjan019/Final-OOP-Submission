#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    string code;
    float price;
    int quantity;
};

int main() {
    Product products[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for product " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> ws;
        getline(cin, products[i].name);

        cout << "Code: ";
        cin >> products[i].code;

        cout << "Price: ";
        cin >> products[i].price;

        cout << "Quantity: ";
        cin >> products[i].quantity;
    }

    cout << "\nProducts with quantity less than 10:\n";

    for (int i = 0; i < 5; i++) {
        if (products[i].quantity < 10) {
            cout << "\nName: " << products[i].name << endl;
            cout << "Code: " << products[i].code << endl;
            cout << "Price: " << products[i].price << endl;
            cout << "Quantity: " << products[i].quantity << endl;
        }
    }
system("pause");
    return 0;
}
