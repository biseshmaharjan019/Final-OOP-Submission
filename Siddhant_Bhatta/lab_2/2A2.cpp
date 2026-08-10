#include <iostream>
#include <string>
using namespace std;

struct Product { string name; int code, quantity; double price; };

int main() {
    Product p[5];
    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i+1 << " - Name: "; cin >> p[i].name;
        cout << "Code: ";     cin >> p[i].code;
        cout << "Price: ";    cin >> p[i].price;
        cout << "Quantity: "; cin >> p[i].quantity;
    }
    cout << "\nProducts with quantity < 10:\n";
    for (int i = 0; i < 5; i++)
        if (p[i].quantity < 10)
            cout << p[i].name << " | Code: " << p[i].code
                 << " | Price: " << p[i].price
                 << " | Qty: " << p[i].quantity << "\n";
}