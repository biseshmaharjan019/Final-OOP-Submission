#include<iostream>
#include<string>
using namespace std;
class ATM{
private:
	string ownerName;
	float balance;
	static int totalTransactions;
	static float totalMoneyMoved;
public:
	ATM(string n,float b){
		ownerName=n;
		balance=b;
	}
	void deposit(float amount){
		balance += amount;
		totalTransactions++;
		totalMoneyMoved += amount;
	}
	void withdraw(float amount){
		if(amount<=balance){
			balance -= amount;
			totalTransactions++;
			totalMoneyMoved += amount;
		}
		else{
			cout << "Insufficient balance!\n";
		}
	}
	void display(){
		cout << ownerName << "Balance = " <<balance <<endl;
	}
	static void showStats(){
		cout << "\nTotal Transactions = " <<totalTransactions <<endl;
		cout << "Total Money Moved = " <<totalMoneyMoved <<endl;
	}
};
int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0;
int main()
{
	ATM a1("ABC",3000);
	ATM a2("XYZ",7000);
	a1.deposit(2000);
	a1.withdraw(4000);
	a2.deposit(8000);
	a2.withdraw(1000);
	a1.display();
	a2.display();
	ATM::showStats();
	return 0;
}
