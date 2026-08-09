#include <iostream>
using namespace std;
 
void area(int x,int y){
    cout<<x*y;

}
void peri(int x,int y){
    cout<<2*(x*y);
}

int main(){
int length , breadth;
cout<<"Enter length and breadth";
cin>>length>>breadth;
area(length,breadth);
cout<<" \n";
peri(length,breadth);
}
