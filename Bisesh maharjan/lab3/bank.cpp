#include<iostream>
using namespace std;

class BankAccount {
    private:
        int accountNumber;
        string holderName;
        float balance;

    public:
        BankAccount() 
		{
            accountNumber=0;
            holderName="None";
            balance=0;
        }

        BankAccount(int acc, string name, float bal) 
		{
            accountNumber=acc;
            holderName=name;
            balance=bal;
        }

        ~BankAccount() 
		{
            cout <<"Account of "<<holderName<< " is closed"<<endl;
        }

        void deposit(float amount) 
		{
            balance=balance+amount;
            cout<<"Deposited:"<<amount<<endl;
        }

        void withdraw(float amount) 
		{
            if(amount>balance) 
			{
                cout<<"Insufficient balance"<<endl;
            } 
			else 
			{
                balance = balance - amount;
                cout<<"Withdrawn:"<<amount<<endl;
            }
        }

        void display() {
            cout <<"Account No:"<<accountNumber<<endl;
            cout <<"Name:"<<holderName<<endl;
            cout <<"Balance:"<<balance<<endl;
        }
};

int main() {
    BankAccount b1;
    cout<<"Default Constructor"<<endl;
    b1.display();
    cout<<endl;
    BankAccount b2(1001, "Ram Bahadur", 5000);
    cout<<"Parameterized Constructor"<< endl;
    b2.display();
    cout<< endl;
    b2.deposit(2000);
    b2.withdraw(1000);
    b2.withdraw(9000);
    cout<< endl;
    cout<< "Updated Balance "<<endl;
    b2.display();
    return 0;
}
