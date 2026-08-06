#include<iostream>
using namespace std;
class DividebyzeroException{
public:
	string message(){
		return "Error: Cannot divide by zero.";
	}
};
class NegativeDenominatorException{
public:
	string message(){
		return "Error: Denominator cannot be negative.";
	}	
};
int main()
{
	int a,b;
	cout << "Enter numerator: ";
	cin >> a;
	cout << "Enter denominator: ";
	cin >> b;
	try{
		if(b==0){
			throw DividebyzeroException();
		}
		if(b<0){
			throw NegativeDenominatorException();
		}
		cout << "Result= " << (float)a/b <<endl;
	}
	catch (DividebyzeroException e){
		cout <<e.message() <<endl;
	}
	catch (NegativeDenominatorException e){
		cout <<e.message() <<endl;
	}
	catch(...){
		cout << "Error: Unexpected exception occurred." <<endl;
	}
	return 0;
}
