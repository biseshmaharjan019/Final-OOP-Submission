#include<iostream>
using namespace std;
void compute(){
	int a,b;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	try{
		if(b==0){
			throw "Division by zero";
		}
		cout << "Result= " << (float)a/b <<endl;
	}
	catch(const char *msg){
		cout << "Exception caught in computer(): " <<msg <<endl;
		throw;
	}
}
int main()
{
	try{
		compute();
	}
	catch(const char *msg){
		cout << "Exception caught in main(): " <<msg <<endl;
	}
	return 0;
}
