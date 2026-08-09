#include<iostream>
using namespace std;
class BankAccount{
private:
	int accountNumber;
	string holderName;
	float balance;
public:
	BankAccount(){
		accountNumber=101;
		holderName="ABC";
		balance=10000;
		cout << "Default Constructor called!\n";
	}
	BankAccount(int an,string n,float b){
		accountNumber=an;
		holderName=n;
		balance=b;
		cout << "Parameterized Constructor called!\n";
	}
	void deposit(float amount){
		balance += amount;
	}
	void withdraw(float amount){
		if(amount<=balance){
			balance -= amount;
		}
		else{
			cout << "Insufficient balance!\n";
		}
	}
	void display(){
		cout << "Account Number: " <<accountNumber <<endl;
		cout << "Holder Name: " <<holderName <<endl;
		cout << "Balance: " <<balance <<endl;
	}
	~BankAccount(){
		cout << "Destructor called!\n";
	}
};
int main()
{
	BankAccount a1;
	BankAccount a2(102,"Niharika",7000);
	a2.deposit(8000);
	a2.withdraw(2000);
	a1.display();
	a2.display();
	return 0;
}
