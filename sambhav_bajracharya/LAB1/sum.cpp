//WAP to print the sum of numbers from 1-5 using a for loop
#include<iostream>
using namespace std;
int main()
{
	int i,sum=0;
	for(i=1;i<=5;i++)
	{
		sum+=i;
	}
	cout<<"the sum= "<<sum;
	return 0;
}
