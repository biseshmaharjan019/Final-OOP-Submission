#include<iostream>
using namespace std;
struct patient{

    string name;
    int age;
    string disease;

};
int main(){
    patient p[5];
    int i;
    for (i=0;i<3;i++){
        cout << "Enter name ";
        cin>>p[i].name;
        cout << "Enter age ";
        cin>> p[i].age;
        cout << "Enter disease ";
        cin>>p[i].disease;
    }

     for (i=0;i<3;i++){
        cout << "Name "<< p[i].name<<endl;
        cout << "Age "<< p[i].age<<endl;
        cout << "Disease "<< p[i].disease<<endl;
    }
    return 0;

}
