#include <iostream>
using namespace std;
int main(){
    int arr[7];
    
    int i;
    cout<<"Enter the sales amount per day: "<<endl;
    for(i=0;i<7;i++){
        cout<< "Day "<<i+1<<endl;
        cin>> arr[i];
    }
    return 0;
}