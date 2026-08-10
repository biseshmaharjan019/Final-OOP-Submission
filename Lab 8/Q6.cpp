#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Product {
    int code;
    string name;
    float price;
    int quantity;
};

int main() {
    Product products[5] = {
        {101, "Laptop", 85000, 3},
        {102, "Keyboard", 2500, 10},
        {103, "Mouse", 1200, 15},
        {104, "Monitor", 25000, 5},
        {105, "Printer", 18000, 7}
    };

    ofstream file("products.txt");

    if (!file) {
        cout << "Error creating file." << endl;
        system("pause");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        file << products[i].code << " "
             << products[i].name << " "
             << products[i].price << " "
             << products[i].quantity << endl;
    }

    file.close();

    ifstream input("products.txt");

    cout << "Department Store Products:" << endl;
    cout << "--------------------------" << endl;

    Product p;
    int totalProducts = 0;

    while (input >> p.code >> p.name >> p.price >> p.quantity) {
        cout << "Code: " << p.code << endl;
        cout << "Name: " << p.name << endl;
        cout << "Price: " << p.price << endl;
        cout << "Quantity: " << p.quantity << endl;
        cout << endl;
        totalProducts++;
    }

    input.close();

    /*
    The number of records can also be obtained using the file's
    get pointer and sizeof(Product) when binary objects are stored.
    For example:
        numberOfClients = fileSize / sizeof(Client);
    */

    cout << "Total number of products/records: "
         << totalProducts << endl;

    system("pause");
    return 0;
}
