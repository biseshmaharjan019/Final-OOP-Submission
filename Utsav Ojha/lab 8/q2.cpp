#include <iostream>
#include <fstream>
using namespace std;

struct Product
{
    int id;
    char name[30];
    float price;
};

int main()
{
    Product p[5];

    ofstream fout("product.dat", ios::binary);

    for(int i=0;i<5;i++)
    {
        cout<<"Enter Product ID: ";
        cin>>p[i].id;

        cout<<"Enter Product Name: ";
        cin>>p[i].name;

        cout<<"Enter Price: ";
        cin>>p[i].price;

        fout.write((char*)&p[i], sizeof(p[i]));
    }

    fout.close();

    ifstream fin("product.dat", ios::binary);

    cout<<"\nProducts\n";

    while(fin.read((char*)&p[0], sizeof(Product)))
    {
        cout<<p[0].id<<" "
            <<p[0].name<<" "
            <<p[0].price<<endl;
    }

    fin.seekg(0, ios::end);

    int totalProducts = fin.tellg()/sizeof(Product);

    cout<<"\nTotal Products = "<<totalProducts;

    fin.close();

    return 0;
}
