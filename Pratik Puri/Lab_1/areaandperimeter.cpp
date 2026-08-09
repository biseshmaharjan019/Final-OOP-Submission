#include <iostream>
using namespace std;
void area(int length, int breadth){
    cout<<"area = "<<length*breadth;
}
void perimeter(int length, int breadth){
    cout<<"Perimeter = "<<2*(length+breadth);
}
int main(){
    int l,b;
    cout<<"Enter the length and breadth: ";
    cin>>l>>b;
    area(l,b);
    perimeter(l,b);
    return 0;
}