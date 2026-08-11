#include <iostream>
using namespace std;
class A{int value;public:A(int v):value(v){cout<<"A constructor: value = "<<value<<endl;}~A(){cout<<"A destructor: value = "<<value<<endl;}};
class B:public A{int valueB;public:B(int a,int b):A(a),valueB(b){cout<<"B constructor: value = "<<valueB<<endl;}~B(){cout<<"B destructor: value = "<<valueB<<endl;}};
class C:public B{int valueC;public:C(int a,int b,int c):B(a,b),valueC(c){cout<<"C constructor: value = "<<valueC<<endl;}~C(){cout<<"C destructor: value = "<<valueC<<endl;}};
int main(){
/* Expected output order:
A constructor: value = 1
B constructor: value = 10
C constructor: value = 100
A constructor: value = 2
B constructor: value = 20
C constructor: value = 200
C destructor: value = 200
B destructor: value = 20
A destructor: value = 2
C destructor: value = 100
B destructor: value = 10
A destructor: value = 1
*/
C obj1(1,10,100);C obj2(2,20,200);system("pause");return 0;}