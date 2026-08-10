#include<iostream>
using namespace std;

template<class T>
T max3(T a,T b,T c)
{
    T max=a;
    if(b>max)
        max=b;
    if(c>max)
        max=c;
    return max;
}

int main()
{
    cout<<"Maximum integer: "<<max3(10,25,15)<<endl;
    cout<<"Maximum float: "<<max3(10.5f,25.7f,15.2f)<<endl;
    cout<<"Maximum character: "<<max3('A','Z','M')<<endl;

    return 0;
}