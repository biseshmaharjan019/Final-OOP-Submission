// WAP which has two function with same name one for addition of two number
//  and another for addition of three number
#include <iostream>
using namespace std;
int ad(int x, int y, int z)
{
    return x + y + z;
}
int ad(int x, int y)
{
    return x + y;
}
int main()
{
    int a = 2, b = 3, c = 4;
    int s1 = ad(a, b);
    int s2 = ad(a, b, c);
    cout << "Sum of three is\t" << s2 << endl
         << "Sum of two is\t" << s1;
    return 0;
}
