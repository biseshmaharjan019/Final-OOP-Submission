#include<iostream>
using namespace std;

class box {
    int length;
    int breadth;
    int height;

public:

    box(int l = 1, int b = 1, int h = 1) {
        length = l;
        breadth = b;
        height = h;
    }

    box(const box &other) {
        length = other.length;
        breadth = other.breadth;
        height = other.height;
    }

    ~box() {
        cout << "Box destroyed" << endl;
    }
};

int main() {
    box b1;           
    box b2(2, 3, 4); 
    box b3(2, 3);     
    box b4(b2);       
    return 0;
}