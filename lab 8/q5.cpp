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
    fstream file("account.dat", ios::in|ios::out|ios::binary);

    Account a;
    int acc, choice;

    cout<<"1.Update\n2.Delete\nChoice: ";
    cin>>choice;

    cout<<"Enter Account Number: ";
    cin>>acc;

    while(file.read((char*)&a,sizeof(a)))
    {
        if(a.accNo==acc)
        {
            if(choice==1)
            {
                cout<<"New Balance: ";
                cin>>a.balance;
            }
            else if(choice==2)
            {
                a.accNo=0;
                strcpy(a.firstName,"Deleted");
                strcpy(a.lastName,"Deleted");
                a.balance=0;
            }

            file.seekp(-sizeof(a),ios::cur);
            file.write((char*)&a,sizeof(a));

            break;
        }
    }

    file.close();

    cout<<"Operation Completed.";

    return 0;
}
