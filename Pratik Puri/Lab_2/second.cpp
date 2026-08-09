#include <iostream>
using namespace std;
typedef struct{
    string name;
    int age;
    string disease;
}patient;
int main(){
    patient p[3];
    int i;
    for(i=0;i<3;i++){
        cout<<"For Patient "<<i+1<<endl<<"Enter the name, age and disease"<<endl;
        cin>>p[i].name>>p[i].age>>p[i].disease;
    }
    for(i=0;i<3;i++){
        cout<<"Patient "<<i+1<<" ";
        cout<<"Name: "<<p[i].name<<endl<<"Age: "<<p[i].age<<endl<<"Disease: "<<p[i].disease<<endl;
    }

    return 0;

}