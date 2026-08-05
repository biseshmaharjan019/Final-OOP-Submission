#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product {
public:
    int id;
    char name[30];
    float price;

    void input() {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Product Price: ";
        cin >> price;
    }

    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Price: $" << price << endl;
    }
};

class Client {
public:
    int accNo;
    char name[30];
    float balance;
};

int main() {
    ofstream outFile("products.dat", ios::binary);
    Product p;

    cout << "--- Writing 5 Products to File ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << ":" << endl;
        p.input();
        outFile.write(reinterpret_cast<char*>(&p), sizeof(p));
    }
    outFile.close();

    cout << "\n--- Displaying Products from File ---" << endl;
    ifstream inFile("products.dat", ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        p.display();
    }
    inFile.close();

    ifstream bankFile("clients.dat", ios::binary | ios::ate);
    if (bankFile) {
        streampos fileBytes = bankFile.tellg();
        int totalClients = fileBytes / sizeof(Client);
        cout << "\nTotal number of bank clients: " << totalClients << endl;
        bankFile.close();
    } else {
        cout << "\nNote: clients.dat file does not exist yet." << endl;
    }

    return 0;
}
