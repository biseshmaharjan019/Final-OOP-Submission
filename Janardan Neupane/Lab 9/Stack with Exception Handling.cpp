#include<iostream>
#include<string>
using namespace std;

template<class T>
class Stack
{
    T arr[5];
    int top;

public:
    Stack()
    {
        top=-1;
    }

    void push(T value)
    {
        if(top==4)
            throw "Stack Overflow";
        arr[++top]=value;
    }

    T pop()
    {
        if(top==-1)
            throw "Stack Underflow";
        return arr[top--];
    }

    void display()
    {
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    Stack<int> s1;
    Stack<string> s2;

    try
    {
        s1.push(10);
        s1.push(20);
        s1.push(30);

        s2.push("Apple");
        s2.push("Banana");
        s2.push("Mango");

        cout<<"Integer Stack: ";
        s1.display();

        cout<<"String Stack: ";
        s2.display();

        s1.push(40);
        s1.push(50);
        s1.push(60);
    }
    catch(const char *msg)
    {
        cout<<"Exception: "<<msg<<endl;
    }

    try
    {
        cout<<"Popped: "<<s1.pop()<<endl;
        cout<<"Popped: "<<s1.pop()<<endl;
        cout<<"Popped: "<<s1.pop()<<endl;
        cout<<"Popped: "<<s1.pop()<<endl;
        cout<<"Popped: "<<s1.pop()<<endl;
        cout<<"Popped: "<<s1.pop()<<endl;
    }
    catch(const char *msg)
    {
        cout<<"Exception: "<<msg<<endl;
    }

    return 0;
}