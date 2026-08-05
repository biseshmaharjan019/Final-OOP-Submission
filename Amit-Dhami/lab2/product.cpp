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
for(int i = 0; i < 5; i++) {
    cout << "Enter product name: ";
    cin >> p[i].name;
cout << "Enter code: ";
        cin >> p[i].code;
cout << "Enter price: ";
        cin >> p[i].price;
cout << "Enter quantity: ";
        cin >> p[i].quantity;
    }
cout << "\nProducts with quantity less than 10:\n";
for(int i = 0; i < 5; i++) {
        if(p[i].quantity < 10) {
            cout << "Name: " << p[i].name << endl;
            cout << "Code: " << p[i].code << endl;
            cout << "Price: " << p[i].price << endl;
            cout << "Quantity: " << p[i].quantity << endl;
            cout << endl;
        }
    }
return 0;
}
