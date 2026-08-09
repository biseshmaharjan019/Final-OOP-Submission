#include <iostream>
#include <fstream>
using namespace std;

class Product {
public:
    char name[30];
    float price;
    int qty;
};

int main() {
    Product p[5] = {
        {"Soap", 50.0, 20},
        {"Shampoo", 120.0, 15},
        {"Toothpaste", 60.0, 25},
        {"Brush", 30.0, 40},
        {"Oil", 200.0, 10}
    };

    ofstream fout("products.dat", ios::binary);
    for (int i = 0; i < 5; i++)
        fout.write((char*)&p[i], sizeof(p[i]));
    fout.close();

    ifstream fin("products.dat", ios::binary);
    Product temp;
    while (fin.read((char*)&temp, sizeof(temp))) {
        cout << temp.name << " " << temp.price << " " << temp.qty << endl;
    }
    fin.close();

    fin.open("products.dat", ios::binary);
    fin.seekg(0, ios::end);
    int total = fin.tellg() / sizeof(Product);
    cout << "Total clients: " << total << endl;
    fin.close();
}
