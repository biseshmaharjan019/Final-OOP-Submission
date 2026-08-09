#include<iostream>
#include<fstream>
using namespace std;

class Account
{
public:
    int accountNo;
    char lastName[30];
    char firstName[30];
    float balance;

    void input()
    {
        cout<<"Account Number: ";
        cin>>accountNo;
        cout<<"Last Name: ";
        cin>>lastName;
        cout<<"First Name: ";
        cin>>firstName;
        cout<<"Balance: ";
        cin>>balance;
    }

    void display()
    {
        cout<<"Account Number: "<<accountNo<<endl;
        cout<<"Last Name: "<<lastName<<endl;
        cout<<"First Name: "<<firstName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

int main()
{
    Account a;
    fstream file;
    int choice, position;

    do
    {
        cout<<"\n1. Add Account";
        cout<<"\n2. Display Account";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"\nEnter account position: ";
            cin>>position;

            a.input();

            file.open("accounts.dat",ios::in|ios::out|ios::binary);

            if(!file)
            {
                file.open("accounts.dat",ios::out|ios::binary);
                file.close();
                file.open("accounts.dat",ios::in|ios::out|ios::binary);
            }

            file.seekp(position*sizeof(Account),ios::beg);
            file.write((char*)&a,sizeof(a));

            file.close();
        }

        else if(choice==2)
        {
            cout<<"\nEnter account position: ";
            cin>>position;

            file.open("accounts.dat",ios::in|ios::binary);

            file.seekg(position*sizeof(Account),ios::beg);
            file.read((char*)&a,sizeof(a));

            if(file)
                a.display();
            else
                cout<<"Account not found."<<endl;

            file.close();
        }

    }while(choice!=3);

    return 0;
}
