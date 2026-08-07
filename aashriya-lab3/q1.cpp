#include <iostream>
#include <string>
using namespace std;
class Box{
    private:
    double length;
    double breadth;
    double height;
    public:
    Box(){
        length = 0;
        breadth = 0;
        height = 0;
        cout<<"Default constructor called."<<endl;
    }
    // Box(double l, double b, double h){
    //     length = l;
    //     breadth = b;
    //     height = h;
    //     cout<<"Parameterized constructor called."<<endl;
    // }
    Box(double l=0.0, double b=0.0, double h=0.0){
        length = l;
        breadth = b;
        height = h;
        cout<<"Parameterized constructor with default arguments called."<<endl;
    }

    
    Box(Box &b){
        length = b.length;
        breadth = b.breadth;
        height = b.height;
        cout<<"Copy constructor called."<<endl;
    }
    double volume(){
        return length * breadth * height;
    }
    ~Box(){
        cout<<"Destructor called."<<endl;
    }
};
int main(){
    // Box box1; // Default constructor
    Box box2(2.0f, 3.0f, 4.0f); // Parameterized constructor
    Box box3(box2); // Copy constructor

    // cout<<"Volume of box1: "<<box1.volume()<<endl;
    cout<<"Volume of box2: "<<box2.volume()<<endl;
    cout<<"Volume of box3: "<<box3.volume()<<endl;

    return 0;
}