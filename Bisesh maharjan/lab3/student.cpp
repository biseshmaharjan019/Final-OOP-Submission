#include<iostream>
using namespace std;

class StudentClass {
    private:
        int *ids;
        int size;

    public:
        StudentClass(int n) 
		{
			int i;
            size=n;
            ids=new int[size];
            cout<<"Enter "<<size<<" student IDs:"<< endl;
            for(i=0;i<size;i++) 
			{
                cout<<"ID "<<i+1<<": ";
                cin>>ids[i];
            }
        }

        void display()
		{
			int i;
            cout<<endl<<"Student IDs:"<<endl;
            for(i= 0;i<size;i++) 
			{
                cout<<"ID"<<i+1<<":"<<ids[i]<<endl;
            }
        }

        ~StudentClass() {
            delete[] ids;
            cout<<"Memory freed"<<endl;
        }
};

int main() {
    int n;
    cout<<"How many students?";
    cin>>n;
    StudentClass s(n);
    s.display();
    return 0;
}
