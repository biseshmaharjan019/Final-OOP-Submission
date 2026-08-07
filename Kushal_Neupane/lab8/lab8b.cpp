#include <iostream>
#include <fstream>
#include <string>

class Product {
public:
    int id;
    char name[30];
    float price;

    void input() {
        std::cout << "Enter Product ID: ";
        std::cin >> id;
        std::cout << "Enter Product Name: ";
        std::cin.ignore();
        std::cin.getline(name, 30);
        std::cout << "Enter Product Price: ";
        std::cin >> price;
    }

    void display() const {
        std::cout << "ID: " << id << " | Name: " << name << " | Price: $" << price << std::endl;
    }
};

class Client {
public:
    int id;
    char name[30];
};

int main() {
    std::ofstream outFile("products.dat", std::ios::binary);
    std::cout << "--- Enter Information for 5 Products ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "\nProduct " << (i + 1) << ":" << std::endl;
        Product p;
        p.input();
        outFile.write(reinterpret_cast<char*>(&p), sizeof(Product));
    }
    outFile.close();

    std::ifstream inFile("products.dat", std::ios::binary);
    std::cout << "\n--- Displaying Store Products ---" << std::endl;
    Product tempP;
    while (inFile.read(reinterpret_cast<char*>(&tempP), sizeof(Product))) {
        tempP.display();
    }
    inFile.close();

    std::ofstream clientFile("clients.dat", std::ios::binary);
    Client c1 = {101, "Alice"};
    Client c2 = {102, "Bob"};
    Client c3 = {103, "Charlie"};
    clientFile.write(reinterpret_cast<char*>(&c1), sizeof(Client));
    clientFile.write(reinterpret_cast<char*>(&c2), sizeof(Client));
    clientFile.write(reinterpret_cast<char*>(&c3), sizeof(Client));
    clientFile.close();

    std::ifstream readClients("clients.dat", std::ios::binary | std::ios::ate);
    std::streampos fileSize = readClients.tellg();
    int totalClients = fileSize / sizeof(Client);
    readClients.close();

    std::cout << "\nTotal number of clients in the bank: " << totalClients << std::endl;

    return 0;
}