#include<iostream>
using namespace std;

class Box{
    float l, b, h;
public:
    Box(float l, float b = 2.0, float h = 3.0){
        this->l = l; this->b = b; this->h = h;
        cout<<"Default arguments constructor called"<<endl;
    }
    ~Box(){
        cout<<"Destructor called"<<endl;
    }
};

int main(){
    Box b1(5.0);
    return 0;
}
