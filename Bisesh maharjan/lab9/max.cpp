#include <iostream>
using namespace std;

template <class T>
T max3(T a, T b, T c){
    T m = a;
    if(b>m) m=b;
    if(c>m) m=c;
    return m;
}

int main(){
    cout<<max3(3,7,5)<<endl;
    cout<<max3(3.5f,2.1f,9.9f)<<endl;
    cout<<max3('a','z','m')<<endl;
    return 0;
}

