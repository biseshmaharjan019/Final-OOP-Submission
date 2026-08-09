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
        Account a = {0,"","",0};
        for(int i=0;i<100;i++)
            file.write((char*)&a,sizeof(Account));
        file.close();
        file.open("Account.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    Account a;

    do{
        cout << "\n1. Add Account";
        cout << "\n2. Display Account";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice==1){
            a.input();
            file.seekp((a.accNumber-1)*sizeof(Account));
            file.write((char*)&a,sizeof(Account));
        }
        else if(choice==2){
            int num;
            cout << "Enter Account Number: ";
            cin >> num;

            file.seekg((num-1)*sizeof(Account));
            file.read((char*)&a,sizeof(Account));

            if(a.accNumber!=0)
                a.display();
            else
                cout << "Account not found!" << endl;
        }

    }while(choice!=3);

    file.close();
    return 0;
}
