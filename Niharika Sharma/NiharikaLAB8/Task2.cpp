#include<iostream>
#include<fstream>
using namespace std;
class Product{
private:
    int id;
    char name[20];
    float price;
public:
    void input(){
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter product ID: ";
        cin >> id;
        cout << "Enter product price: ";
        cin >> price;
    }
    void display(){
        cout << "Name: " << name <<endl;
        cout << "ID: " << id <<endl;
        cout <<"Price: " << price <<endl;
    }
};
int main()
{
    Product p;
    fstream file;
    file.open("product.dat",ios::out|ios::binary);
    for(int i=0;i<5;i++)
    {
        cout << "\nEnter details of Product " <<i+1 <<endl;
        p.input();
        file.write((char*)&p,sizeof(p));
    }
    file.close();
    file.open("product.dat",ios::in|ios::binary);
    cout << "\n\nProduct Records:\n";
    while(file.read((char*)&p,sizeof(p)))
    {
        p.display();
        cout << endl;
    }
    file.clear();
    file.seekg(0,ios::end);
    int total=file.tellg()/sizeof(p);
    cout << "Total number of products: " <<total <<endl;
    file.close();
    return 0;
}
