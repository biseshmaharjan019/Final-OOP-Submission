#include <iostream>
#include <fstream>
using namespace std;

class P {
public:
    int id;
    char n[30];
    double p;
};

class C {
public:
    int acc;
    char n[30];
};

int main() {
    ofstream o1("products.dat", ios::binary);
    P arr[5] = {
        {101, "Pen", 1.5},
        {102, "Notebook", 3.0},
        {103, "Bag", 25.0},
        {104, "Marker", 2.0},
        {105, "Eraser", 0.5}
    };
    o1.write((char*)&arr, sizeof(arr));
    o1.close();

    ifstream i1("products.dat", ios::binary);
    P t;
    cout << "Products:\n";
    while (i1.read((char*)&t, sizeof(P))) {
        cout << "ID: " << t.id << ", Name: " << t.n << ", Price: $" << t.p << endl;
    }
    i1.close();

    ofstream o2("bank.dat", ios::binary);
    C c[3] = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
    o2.write((char*)&c, sizeof(c));
    o2.close();

    ifstream i2("bank.dat", ios::binary);
    i2.seekg(0, ios::end);
    long bytes = i2.tellg();
    int total = bytes / sizeof(C);
    i2.close();

    cout << "\nTotal clients: " << total << endl;
    return 0;
}
