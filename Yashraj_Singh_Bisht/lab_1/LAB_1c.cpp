// Lab task three printing sum using loop

#include <iostream>
using namespace std;

int main() {
	int sum=0;
	for (int i = 1; i <= 5; i++)
	{
		sum+=i;
	}

	cout<<"Sum of 1,2,3,4,5 = " <<sum;
 return 0;
}
