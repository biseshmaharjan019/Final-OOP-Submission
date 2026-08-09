#include <iostream>
#include <fstream>
using namespace std;

class Product {
public:
    int id;
    char name[30];
    double price;
};

class Client {
public:
    int accountNum;
    char name[30];
};

int main() {
    ofstream outProd("products.dat", ios::binary);
    Product p[5] = {
        {101, "Pen", 1.5},
        {102, "Notebook", 3.0},
        {103, "Bag", 25.0},
        {104, "Marker", 2.0},
        {105, "Eraser", 0.5}
    };
    outProd.write((char*)&p, sizeof(p));
    outProd.close();

    ifstream inProd("products.dat", ios::binary);
    Product temp;
    cout << "Product Information:" << endl;
    while (inProd.read((char*)&temp, sizeof(Product))) {
        cout << "ID: " << temp.id << ", Name: " << temp.name << ", Price: $" << temp.price << endl;
    }
    inProd.close();

    ofstream outClient("bank.dat", ios::binary);
    Client c[3] = { {1, "Alice"}, {2, "Bob"}, {3, "Charlie"} };
    outClient.write((char*)&c, sizeof(c));
    outClient.close();

    ifstream inClient("bank.dat", ios::binary);
    inClient.seekg(0, ios::end);
    long totalBytes = inClient.tellg();
    int totalClients = totalBytes / sizeof(Client);
    inClient.close();

    cout << "\nTotal number of clients in bank: " << totalClients << endl;
    return 0;
}
