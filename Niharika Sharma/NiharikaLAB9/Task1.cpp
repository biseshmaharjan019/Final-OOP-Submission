#include<iostream>
using namespace std;
template<class T>
T max(T a,T b,T c)
{
	T max=a;
	if(b>max){
		max=b;
	}
	if(c>max){
		max=c;
	}
	return max;
}
int main()
{
	cout << "Maximum of integers: " << max(10,30,20) <<endl;
	cout << "Maximum of floats: " << max(10.5,23.5,100.5) <<endl;
	cout << "Maximum of characters: " <<max('N','A','S');
	return 0;
}
