//WAP to store daily sales amounts for a week. 
//Calculate and display the total and average sales.
#include<iostream>
using namespace std;
int main()
{
    float sales[7],total=0,avg;
    cout<<"Enter sales amount for 7 days";
    for(int i=0;i<7;i++)
    {
        cout<<"Day "<<i+1<<": ";
        cin>>sales[i];
        total=total+sales[i];
    }
    avg=total/7;
    cout<<"\nTotal Sales = "<<total;
    cout<<"\nAverage Sales = "<<avg;
    return 0;
}
