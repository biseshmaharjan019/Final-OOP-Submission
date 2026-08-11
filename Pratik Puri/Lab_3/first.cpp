#include <iostream>
using namespace std;
class Box{
    float l,b,h;

    public:
    Box(){
        cout<<"Default Constructor Called"<<endl;
    }
    Box(float length,float breadth,float height){
        l = length;
        b = breadth;
        h = height;

        cout<<"Paramaterized Constructor Called"<<endl;
    }
    // Box(float lgth, float brdth, float hght = 4.0){
    //     l = lgth;
    //     b = brdth;
    //     h = hght;

    //     cout<<"Constructor with default Value called"<<endl;
    // }
    Box(const Box& copy){
        l = copy.l;
        b = copy.b;
        h = copy.h;

        cout<<"Copy Constructor Called"<<endl;
    }
    ~Box(){
    cout<<"Constructor died";
    };
};


int main(){
    Box b1;
    Box b2(2.0,3.0,2.0);
    // Box b3(1.0,2.0);
    Box b4 = b2;
    return 0;
}