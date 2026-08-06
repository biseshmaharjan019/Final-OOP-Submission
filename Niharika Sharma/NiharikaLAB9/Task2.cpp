#include<iostream>
#include<string>
using namespace std;
#define size 3
template<class T> 
class Stack{
	T arr[size];
	int top;
public: 
	Stack(){
		top=-1;
	}
	void push(T x){
		if(top==size-1){
			throw "Stack Overflow";
		}
		arr[++top]=x;
	}
	void pop(){
		if(top==-1){
			throw "Stack Underflow";
		}
		cout << "Popped: " << arr[top--] <<endl;
	}
	void display(){
		for(int i=top;i>=0;i--){
			cout << arr[i] <<" ";
		}
		cout <<endl;
	}
};
int main()
{
	Stack<int> s1;
	Stack<string> s2;
	try{
		s1.push(10);
		s1.push(20);
		s1.push(30);
		cout << "Integer Stack: ";
		s1.display();
		s2.push("Apple");
		s2.push("Banana");
		s2.push("Mango");
		cout << "String Stack: ";
		s2.display();
		s1.pop();
		s2.pop();
		/*
		s1.push(40);        //For overflow
		s1.pop();
		s1.pop();
		s1.pop();
		s1.pop();           //For underflow 
		*/
	}
	catch(const char *msg){
		cout << "Exception: " <<msg <<endl;
	}
	return 0;
}
