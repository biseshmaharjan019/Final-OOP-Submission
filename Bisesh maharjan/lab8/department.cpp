#include <iostream>
#include <fstream>
using namespace std;

class Product{
public:
    int id;
    char name[30];
    float price;
    int qty;
};

int main(){
    Product p[5] = {
        {1,"Pen",10.5,100},
        {2,"Pencil",5.0,150},
        {3,"Notebook",30.0,80},
        {4,"Eraser",3.0,200},
        {5,"Sharpener",7.5,120}
    };

    ofstream outfile("products.dat", ios::binary);
    for(int i=0;i<5;i++)
        outfile.write(reinterpret_cast<char*>(&p[i]), sizeof(Product));
    outfile.close();

    ifstream infile("products.dat", ios::binary);
    Product temp;
    cout<<"Products:"<<endl;
    while(infile.read(reinterpret_cast<char*>(&temp), sizeof(Product))){
        cout<<temp.id<<" "<<temp.name<<" "<<temp.price<<" "<<temp.qty<<endl;
    }
    infile.clear();
    infile.seekg(0, ios::end);
    int total = infile.tellg()/sizeof(Product);
    cout<<"Total number of clients: "<<total<<endl;
    infile.close();

    return 0;
}

