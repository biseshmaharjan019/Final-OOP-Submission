#include<iostream>
using namespace std;
int is_prime(int n)
{
	int i;
	if(n<2)
	{
		return 0;
	}
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n,i;
	int count=0;
	cout << "Enter a number : ";
	cin >> n;
	if(is_prime(n))
	{
		cout << n <<" is a prime number." <<endl;
	}
	else
	{
		cout << n <<" is not a prime number." <<endl;
	}
	for(i=1;i<=n;i++)
	{
		if(is_prime(i))
		{
			count++;
		}
	}
	cout <<"The number of prime numbers from 1 to " << n <<" is " << count <<"." <<endl;
	return 0;
}
