#include<iostream>
using namespace std;

class StudentClass{
    int *ptr;
    int size;
public:
    StudentClass(int n){
        size = n;
        ptr = new int[n];
        cout<<"Enter "<<n<<" student IDs: ";
        for(int i=0; i<n; i++) cin>>ptr[i];
    }
    void display(){
        for(int i=0; i<size; i++) cout<<"ID "<<i+1<<": "<<ptr[i]<<endl;
    }
    ~StudentClass(){
        delete[] ptr;
        cout<<"Memory freed"<<endl;
    }
};

int main(){
    StudentClass s(3);
    s.display();
    return 0;
}
