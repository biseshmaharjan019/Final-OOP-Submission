#include<iostream>
using namespace std;

class Box{
    float l, b, h;
public:
    Box(){
        l = b = h = 0;
        cout<<"Default constructor called"<<endl;
    }
    Box(float l, float b, float h){
        this->l = l; this->b = b; this->h = h;
        cout<<"Parameterised constructor called"<<endl;
    }
    Box(Box &obj){
        l = obj.l; b = obj.b; h = obj.h;
        cout<<"Copy constructor called"<<endl;
    }
    ~Box(){
        cout<<"Destructor called"<<endl;
    }
};

int main(){
    Box b1;
    Box b2(5.0, 3.0, 2.0);
    Box b3(b2);
    return 0;
}
