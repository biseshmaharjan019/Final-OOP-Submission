#include <iostream>
#include <fstream>
using namespace std;

class Product {
public:
    int id;
    char name[30];
    float price;
};

int main() {
    Product p;
    fstream file("product.dat", ios::out | ios::binary);

    for (int i = 0; i < 5; i++) {
        cout << "Enter ID Name Price: ";
        cin >> p.id >> p.name >> p.price;
        file.write((char*)&p, sizeof(p));
    }

    file.close();

    file.open("product.dat", ios::in | ios::binary);

    cout << "\nProducts:\n";
    while (file.read((char*)&p, sizeof(p))) {
        cout << p.id << " " << p.name << " " << p.price << endl;
    }

    file.clear();
    file.seekg(0, ios::end);

    cout << "Total Products: " << file.tellg() / sizeof(Product);

    file.close();
    return 0;
}