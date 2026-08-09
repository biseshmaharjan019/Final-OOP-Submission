#include<iostream>
using namespace std;

class BankAccount{
    int accountNumber;
    string holderName;
    float balance;
public:
    BankAccount(){
        accountNumber = 0; holderName = "Unknown"; balance = 0;
        cout<<"Default constructor called"<<endl;
    }
    BankAccount(int acc, string name, float bal){
        accountNumber = acc; holderName = name; balance = bal;
        cout<<"Parameterised constructor called"<<endl;
    }
    ~BankAccount(){
        cout<<"Destructor called for "<<holderName<<endl;
    }
    void deposit(float amount){ balance += amount; }
    void withdraw(float amount){
        if(amount > balance) cout<<"Insufficient balance"<<endl;
        else balance -= amount;
    }
    void display(){
        cout<<"Account:"<<accountNumber<<" Name:"<<holderName<<" Balance:"<<balance<<endl;
    }
};

int main(){
    BankAccount a1;
    BankAccount a2(101, "Ayush", 5000);
    a2.deposit(2000);
    a2.withdraw(1000);
    a1.display();
    a2.display();
    return 0;
}
