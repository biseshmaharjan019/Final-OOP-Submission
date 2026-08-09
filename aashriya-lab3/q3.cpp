#include<iostream>
#include<string>
using namespace std;
class Bankaccount{
    private:
    int accountnumber;
    string accountname;
    float balance;
    int depositamount;
    int withdrawalamount;
    public:
    Bankaccount(int accnum, string accname, float bal){
        accountnumber = accnum;
        accountname = accname;
        balance = bal;
        depositamount = 0;
        withdrawalamount = 0;
        cout<<"Parameterized constructor called."<<endl;
    }
    void deposit(float amount){
        balance += amount;
        depositamount = amount;
    }
    void withdraw(float amount){
        if(amount > balance){
            cout<<"Insufficient balance."<<endl;
        }
        else{
            balance -= amount;
            withdrawalamount = amount;
        }
    }
    void display(){
        cout<<"Account Number: "<<accountnumber<<endl;
        cout<<"Account Name: "<<accountname<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Deposit Amount: "<<depositamount<<endl;
        cout<<"Withdrawal Amount: "<<withdrawalamount<<endl;
    }
    ~Bankaccount(){
        cout<<"Destructor called."<<endl;
    }
} ;
int main(){
    Bankaccount account1(12345, "John Doe", 1000.0f);
    account1.deposit(500.0f);
    account1.withdraw(200.0f);
    account1.display();
    return 0;
}