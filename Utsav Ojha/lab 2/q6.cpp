#include <iostream>
using namespace std;

struct Product
{
    string name;
    int code;
    float price;
    int quantity;
};

int main()
{
    Product p[5];

    for(int i = 0; i < 5; i++)
    {
        cout << "\nEnter Product " << i + 1 << endl;

        cout << "Name: ";
        cin >> p[i].name;

        cout << "Code: ";
        cin >> p[i].code;

        cout << "Price: ";
        cin >> p[i].price;

        cout << "Quantity: ";
        cin >> p[i].quantity;
    }

    cout << "\nProducts with Quantity less than 10\n";

    for(int i = 0; i < 5; i++)
    {
        if(p[i].quantity < 10)
        {
            cout << "\nName: " << p[i].name << endl;
            cout << "Code: " << p[i].code << endl;
            cout << "Price: " << p[i].price << endl;
            cout << "Quantity: " << p[i].quantity << endl;
        }
    }

    return 0;
}
