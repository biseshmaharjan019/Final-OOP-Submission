#include<iostream>
#include<fstream>
using namespace std;

class Product
{
public:
    int id;
    char name[30];
    float price;

    void input()
    {
        cout<<"Enter Product ID: ";
        cin>>id;
        cout<<"Enter Product Name: ";
        cin>>name;
        cout<<"Enter Price: ";
        cin>>price;
    }

    void display()
    {
        cout<<id<<"\t"<<name<<"\t"<<price<<endl;
    }
};

int main()
{
    Product p;
    fstream file("products.dat",ios::out|ios::binary);

    for(int i=0;i<5;i++)
    {
        cout<<"\nProduct "<<i+1<<endl;
        p.input();
        file.write((char*)&p,sizeof(p));
    }

    file.close();

    file.open("products.dat",ios::in|ios::binary);

    cout<<"\nProduct Information\n";
    cout<<"ID\tName\tPrice\n";

    while(file.read((char*)&p,sizeof(p)))
        p.display();

    file.seekg(0,ios::end);

    long total=file.tellg()/sizeof(Product);

    cout<<"\nTotal number of products/clients: "<<total<<endl;

    file.close();

    return 0;
}
