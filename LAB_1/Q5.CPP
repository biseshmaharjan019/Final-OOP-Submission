// Prime Number Check and Count Primes

#include <iostream>
#include <cstdlib>
using namespace std;

bool is_prime(int n)
{
    if(n < 2)
        return false;

    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n, count = 0;

    cout << "Enter a number: ";
    cin >> n;

    if(is_prime(n))
        cout << n << " is Prime" << endl;
    else
        cout << n << " is Not Prime" << endl;

    for(int i = 1; i <= n; i++)
    {
        if(is_prime(i))
            count++;
    }

    cout << "Total primes from 1 to " << n << " = " << count << endl;

    system("pause");
    return 0;
}