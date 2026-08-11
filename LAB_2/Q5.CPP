// Product Details and Low Stock Display

#include <iostream>
#include <cstdlib>
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
        cout << "\nProduct " << i + 1 << endl;

        cout << "Enter Name: ";
        cin >> p[i].name;

        cout << "Enter Code: ";
        cin >> p[i].code;

        cout << "Enter Price: ";
        cin >> p[i].price;

        cout << "Enter Quantity: ";
        cin >> p[i].quantity;
    }

    cout << "\nProducts with Quantity Less Than 10\n";

    for(int i = 0; i < 5; i++)
    {
        if(p[i].quantity < 10)
        {
            cout << p[i].name << " "
                 << p[i].code << " "
                 << p[i].price << " "
                 << p[i].quantity << endl;
        }
    }

    system("pause");
    return 0;
}