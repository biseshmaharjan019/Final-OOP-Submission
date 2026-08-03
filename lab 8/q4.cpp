#include <iostream>
#include <fstream>
using namespace std;

struct Account
{
    int accNo;
    char firstName[20];
    char lastName[20];
    float balance;
};

int main()
{
    Account a;

    fstream file("account.dat", ios::out|ios::binary);

    for(int i=0;i<3;i++)
    {
        cout<<"Account Number: ";
        cin>>a.accNo;

        cout<<"First Name: ";
        cin>>a.firstName;

        cout<<"Last Name: ";
        cin>>a.lastName;

        cout<<"Balance: ";
        cin>>a.balance;

        file.write((char*)&a,sizeof(a));
    }

    file.close();

    file.open("account.dat", ios::in|ios::binary);

    cout<<"\nAccount Records\n";

    while(file.read((char*)&a,sizeof(a)))
    {
        cout<<a.accNo<<" "
            <<a.firstName<<" "
            <<a.lastName<<" "
            <<a.balance<<endl;
    }

    file.close();

    return 0;
}
