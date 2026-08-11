// Sum of Numbers from 1 to 5

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int sum = 0;

    for(int i = 1; i <= 5; i++)
        sum += i;

    cout << "Sum = " << sum << endl;

    system("pause");
    return 0;
}