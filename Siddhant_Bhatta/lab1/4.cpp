// WAP with a function which calculate A where A=p(1+R/100)^n for data p r and n
// but for some cases value of r is fixed i.e.15 call this function in main

#include <iostream>
#include <math.h>
using namespace std;

double A(int p, int n, int r = 15)
{
    return p * pow((1 + (r / 100.0)), n);
}

int main()
{
    int p = 100, r = 16, n = 3;

    cout << "Amount with given rate = " << A(p, n, r) << endl;

    cout << "Amount with default rate = " << A(p, n) << endl;

    return 0;
}