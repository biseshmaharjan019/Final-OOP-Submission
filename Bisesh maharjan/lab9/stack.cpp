#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack{
    T arr[5];
    int top;
public:
    class Overflow{};
    class Underflow{};

    Stack(){ top = -1; }

    void push(T val){
        if(top>=4) throw Overflow();
        arr[++top] = val;
    }

    T pop(){
        if(top<0) throw Underflow();
        return arr[top--];
    }

    void display(){
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Stack<int> s1;
    try{
        s1.push(10);
        s1.push(20);
        s1.push(30);
        s1.display();
    } catch(Stack<int>::Overflow){
        cout<<"Stack Overflow"<<endl;
    } catch(Stack<int>::Underflow){
        cout<<"Stack Underflow"<<endl;
    }

    Stack<string> s2;
    try{
        s2.push("Hello");
        s2.push("World");
        s2.push("Test");
        s2.display();
    } catch(Stack<string>::Overflow){
        cout<<"Stack Overflow"<<endl;
    } catch(Stack<string>::Underflow){
        cout<<"Stack Underflow"<<endl;
    }

    return 0;
}

