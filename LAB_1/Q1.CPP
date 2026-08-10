// Perimeter of Rectangle

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    float l, w;

    cout << "Enter length and width: ";
    cin >> l >> w;

    cout << "Perimeter = " << 2 * (l + w) << endl;

    system("pause");
    return 0;
}