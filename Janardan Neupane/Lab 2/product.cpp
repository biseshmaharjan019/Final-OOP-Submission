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
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details of Product " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> p[i].name;
        cout << "Code: ";
        cin >> p[i].code;
        cout << "Price: ";
        cin >> p[i].price;
        cout << "Quantity: ";
        cin >> p[i].quantity;
    }
    cout << "\nProducts with quantity less than 10:\n";
    for (int i = 0; i < 5; i++) {
        if (p[i].quantity < 10) {
            cout << p[i].name << " "
                 << p[i].code << " "
                 << p[i].price << " "
                 << p[i].quantity << endl;
        }
    }
    return 0;
}