#include <iostream>
using namespace std;
int main()
{
    int i, s = 0;
    for (i = 1; i <= 5; i = i + 1)
    {
        s = s + i;
    }
    cout << "Sum:" << s << endl;
    return 0;
}