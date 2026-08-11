// Area and Perimeter Using Separate Functions

#include <iostream>
#include <cstdlib>
using namespace std;

float area(float l, float w)
{
    return l * w;
}

float perimeter(float l, float w)
{
    return 2 * (l + w);
}

int main()
{
    float l, w;

    cout << "Enter length and width: ";
    cin >> l >> w;

    cout << "Area = " << area(l, w) << endl;
    cout << "Perimeter = " << perimeter(l, w) << endl;

    system("pause");
    return 0;
}