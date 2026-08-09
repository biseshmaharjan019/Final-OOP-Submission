#include <iostream>
using namespace std;
int area(int l, int b)
{
    return l * b;
}
int perimeter(int l, int b)
{
    return 2 * (l + b);
}
int main()
{
    int l, b;
    cout << "Enter length and breadth:" << endl;
    cin >> l >> b;
    cout << "Area:" << area(l, b) << endl;
    cout << "Perimeter:" << perimeter(l, b);
    return 0;
}