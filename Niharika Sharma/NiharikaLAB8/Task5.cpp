#include<iostream>
#include<fstream>
using namespace std;

class Account{
public:
    int accNumber;
    char lastName[20];
    char firstName[20];
    float balance;

    void input(){
        cout << "Enter Account Number: ";
        cin >> accNumber;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void display(){
        cout << "\nAccount Number: " << accNumber << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main(){
    fstream file("Account.dat", ios::in | ios::out | ios::binary);

    if(!file){
        file.open("Account.dat", ios::out | ios::binary);
        Account empty = {0,"","",0};
        for(int i=0;i<100;i++)
            file.write((char*)&empty, sizeof(Account));
        file.close();

        file.open("Account.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    Account a, empty = {0,"","",0};

    do{
        cout << "\n1. Add Account";
        cout << "\n2. Display Account";
        cout << "\n3. Update Account";
        cout << "\n4. Delete Account";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice){

        case 1:
            a.input();
            file.seekp((a.accNumber-1)*sizeof(Account));
            file.write((char*)&a,sizeof(Account));
            break;

        case 2:{
            int num;
            cout << "Enter Account Number: ";
            cin >> num;

            file.seekg((num-1)*sizeof(Account));
            file.read((char*)&a,sizeof(Account));

            if(a.accNumber!=0)
                a.display();
            else
                cout << "Account not found!" << endl;
            break;
        }

        case 3:{
            int num;
            cout << "Enter Account Number to Update: ";
            cin >> num;

            file.seekg((num-1)*sizeof(Account));
            file.read((char*)&a,sizeof(Account));

            if(a.accNumber!=0){
                cout << "Enter New Details:\n";
                a.input();
                file.seekp((a.accNumber-1)*sizeof(Account));
                file.write((char*)&a,sizeof(Account));
                cout << "Account Updated Successfully." << endl;
            }
            else
                cout << "Account not found!" << endl;
            break;
        }

        case 4:{
            int num;
            cout << "Enter Account Number to Delete: ";
            cin >> num;

            file.seekp((num-1)*sizeof(Account));
            file.write((char*)&empty,sizeof(Account));

            cout << "Account Deleted Successfully." << endl;
            break;
        }

        }

    }while(choice!=5);

    file.close();
    return 0;
}
