#include <iostream>
using namespace std;
class   Studentclass{
    private:
    int *id;
    int size;
    public:
    Studentclass(int n)
    {
        size=n;
        id=new int[size];

        cout<<"enter" <<size<<"students ids\n";
    {
        for(int i=0;i<size;i++)
        {
            cin>>id[i];
        }
    } }
    void display()
    {
        cout<<"students ids are\n";
        for(int i=0;i<size;i++)
        {
            cout<<id[i]<<endl;
        }
    }
    ~Studentclass()
    {
        delete []id;
        cout<<"destructor called\n";
}
    };

    int main()
    {
        int n;
        cout<<"enter number of students\n";
        cin>>n;
        Studentclass s1(n);
        s1.display();
        return 0;
    }