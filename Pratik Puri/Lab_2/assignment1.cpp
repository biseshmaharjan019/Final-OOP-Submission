#include <iostream>
using namespace std;
int main(){
    int seats[10] = {0};
    int choice;
    int i;
    for(i=0;i<10;i++){
        if(seats[i]==0){
            cout<<"Available"<<" ";
        }
        else{
            cout<<"Booked";
        }
    }
    cout<<"\nEnter the seat number to choose (1-10)";
    cin>>choice;
    if(choice<1||choice>10){
        cout<<"Invalid choice\n";
    }
    else if(seats[choice-1]==1){
        cout<<"Seat already booked\n";
    }
    else{
        seats[choice-1]=1;
        cout<<"Seat booked successfully\n";
    }
    for(i=0;i<10;i++){
        cout<<"Seats "<<i+1<<": ";
        if(seats[i]==0){
            cout<<"Available";
        }
        else{
            cout<<"Booked";
        }
        cout<<endl;
    }
    return 0;
}