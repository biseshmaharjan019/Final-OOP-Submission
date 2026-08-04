// Lab task two area of rectangle using functions

#include <iostream>
using namespace std;

float area(float len, float wid){
	float are;
	return len*wid;
}


int main() {
 float length, width;

 cout << "Enter length of the rectangle: ";
 cin >> length;
 cout << "Enter width of the rectangle: ";
 cin >> width;

 cout << "Area of the rectangle = " << area(length,width) << endl;
 return 0;
}
