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
        cout<<"\n3. Update Account";
        cout<<"\n4. Delete Account";
        cout<<"\n5. Exit";
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

            cout<<"Account added successfully."<<endl;
        }

        else if(choice==2)
        {
            cout<<"\nEnter account position: ";
            cin>>position;

            file.open("accounts.dat",ios::in|ios::binary);
            file.seekg(position*sizeof(Account),ios::beg);
            file.read((char*)&a,sizeof(a));

            if(file && a.accountNo!=0)
                a.display();
            else
                cout<<"Account not found."<<endl;

            file.close();
        }

        else if(choice==3)
        {
            cout<<"\nEnter account position to update: ";
            cin>>position;

            file.open("accounts.dat",ios::in|ios::out|ios::binary);
            file.seekg(position*sizeof(Account),ios::beg);
            file.read((char*)&a,sizeof(a));

            if(file && a.accountNo!=0)
            {
                cout<<"Enter new account information:\n";
                a.input();

                file.seekp(position*sizeof(Account),ios::beg);
                file.write((char*)&a,sizeof(a));

                cout<<"Account updated successfully."<<endl;
            }
            else
                cout<<"Account not found."<<endl;

            file.close();
        }

        else if(choice==4)
        {
            cout<<"\nEnter account position to delete: ";
            cin>>position;

            file.open("accounts.dat",ios::in|ios::out|ios::binary);
            file.seekg(position*sizeof(Account),ios::beg);
            file.read((char*)&a,sizeof(a));

            if(file && a.accountNo!=0)
            {
                a.accountNo=0;
                a.lastName[0]='\0';
                a.firstName[0]='\0';
                a.balance=0;

                file.seekp(position*sizeof(Account),ios::beg);
                file.write((char*)&a,sizeof(a));

                cout<<"Account deleted successfully."<<endl;
            }
            else
                cout<<"Account not found."<<endl;

            file.close();
        }

    }while(choice!=5);

    return 0;
}
