#include<iostream>
using namespace std;

struct Patient{
    string name;
    int age;
    string disease;
};

int main(){
    Patient p[3];
    for(int i=0; i<3; i++){
        cout<<"Name: "; cin>>p[i].name;
        cout<<"Age: "; cin>>p[i].age;
        cout<<"Disease: "; cin>>p[i].disease;
    }
    for(int i=0; i<3; i++){
        cout<<p[i].name<<" "<<p[i].age<<" "<<p[i].disease<<endl;
    }
    return 0;
}
