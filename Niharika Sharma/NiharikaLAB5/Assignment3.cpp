#include<iostream>
using namespace std;
class Vector3D{
private:
	int x,y,z;
public:
	Vector3D(int a=0,int b=0,int c=0){
		x=a;
		y=b;
		z=c;
	}
	void input(){
		cout << "Enter x,y and z:\n";
		cin >> x >> y >> z;
	}
	void display(){
		cout << "(" << x << ", " << y << ", " << z << ")";
	}
	Vector3D operator+(Vector3D v){
		Vector3D temp;
		temp.x=x+v.x;
		temp.y=y+v.y;
		temp.z=z+v.z;
		return temp;
	}
	Vector3D operator*(int n){
		Vector3D temp;
		temp.x=x*n;
		temp.y=y*n;
		temp.z=z*n;
		return temp;
	}
	friend Vector3D operator*(int n,Vector3D v);
	int dotProduct(Vector3D v){
		return (x*v.x+y*v.y+z*v.z);
	}
};
Vector3D operator *(int n,Vector3D v){
	return v*n;
}
int main()
{
	Vector3D v1,v2,sum,result;
	int dot;
	cout << "Enter first vector:\n";
	v1.input();
	cout << "\nEnter second vector:\n";
	v2.input();
	sum=v1+v2;
	cout << "\nFirst Vector: ";
	v1.display();
	cout << "\nSecond Vector: ";
	v2.display();
	cout << "\n\nSum of vectors: ";
	sum.display();
	result=v1*3;
	cout << "\n\nv1 * 3 = ";
	result.display();
	result=2*v2;
	cout << "\n2 * v2 = ";
	result.display();
	dot=v1.dotProduct(v2);
	cout << "\n\nDot Product = " << dot;
	return 0;
}
