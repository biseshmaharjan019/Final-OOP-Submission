#include<iostream>
using namespace std;

class box {
private:
	float l, b, h;

public:
	box() {
		l=0.0;
		b=0.0;
		h=0.0;
		cout << "default constructor called." << endl;
	}

	box(float len, float bre, float hei=0.0){
		l=len;
		b=bre;
		h=hei;
		cout << " parameterized constructor" << endl;
	}

	box(const box &obj) {
		l= obj.l;
		b= obj.b;
		h= obj.h;
		cout << "copy constructor called" << endl;
	}

	~box(){
		cout <<"destructor called: object destroyed" << endl;
	}

	void display() const {
		cout << "dimensions: "<< l << "x" << b << "x" << h << endl;
	}
};

int main(){
	cout<<"creating object"<< endl;
box b1;
b1.display();

cout << "creating object 2" << endl;
box b2(5.5,4.3,3.5);
b2.display();

cout << "creating object 3" << endl;
box b3(7.3,5.2);
b3.display();

cout << "creating object 4" << endl;
box b4=b2;
b4.display();

return 0;

}