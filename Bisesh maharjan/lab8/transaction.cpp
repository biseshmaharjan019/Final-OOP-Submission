#include <iostream>
#include <fstream>
using namespace std;

class Account{
public:
    int accNo;
    char lastName[20];
    char firstName[20];
    float balance;
};

void addAccount(){
    fstream file("accounts.dat", ios::in|ios::out|ios::binary);
    Account a;
    cout<<"Enter account number: ";
    cin>>a.accNo;
    cout<<"Enter last name: ";
    cin>>a.lastName;
    cout<<"Enter first name: ";
    cin>>a.firstName;
    cout<<"Enter balance: ";
    cin>>a.balance;
    file.seekp(a.accNo*sizeof(Account));
    file.write(reinterpret_cast<char*>(&a), sizeof(Account));
    file.close();
}

void displayAccount(){
    ifstream file("accounts.dat", ios::binary);
    int accNo;
    cout<<"Enter account number to display: ";
    cin>>accNo;
    Account a;
    file.seekg(accNo*sizeof(Account));
    file.read(reinterpret_cast<char*>(&a), sizeof(Account));
    if(a.accNo==0){
        cout<<"Account not found"<<endl;
    } else {
        cout<<a.accNo<<" "<<a.lastName<<" "<<a.firstName<<" "<<a.balance<<endl;
    }
    file.close();
}

int main(){
    ofstream create("accounts.dat", ios::app);
    create.close();

    int choice;
    do{
        cout<<endl<<"1. Add Account"<<endl<<"2. Display Account"<<endl<<"3. Exit"<<endl<<"Enter choice: ";
        cin>>choice;
        if(choice==1) addAccount();
        else if(choice==2) displayAccount();
    }while(choice!=3);

    return 0;
}

