#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Product {
public:
    int id;
    char name[50];
    float price;

    void getData() {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Product Price: ";
        cin >> price;
    }

    void showData() const {
        cout << "ID: " << id << " | Name: " << name << " | Price: " << price << endl;
    }
};

int main() {
    ofstream fout("products.dat", ios::binary);
    Product p;

    cout << "--- Input 5 Products ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << ":" << endl;
        p.getData();
        fout.write(reinterpret_cast<char*>(&p), sizeof(p));
    }
    fout.close();

    ifstream fin("products.dat", ios::binary);
    cout << "\n--- Displaying Product Information ---" << endl;
    while (fin.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        p.showData();
    }

    fin.clear();
    fin.seekg(0, ios::end);
    int totalRecords = fin.tellg() / sizeof(Product);
    cout << "\nTotal number of records in file: " << totalRecords << endl;

    fin.close();
    return 0;
}