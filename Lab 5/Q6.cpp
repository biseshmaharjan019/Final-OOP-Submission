#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
    float x,y,z;
public:
    Vector3D(float value=0):x(value),y(value),z(value){}
    Vector3D(float a,float b,float c):x(a),y(b),z(c){}
    Vector3D operator+(const Vector3D&v)const{return Vector3D(x+v.x,y+v.y,z+v.z);}
    Vector3D operator-(const Vector3D&v)const{return Vector3D(x-v.x,y-v.y,z-v.z);}
    Vector3D operator-()const{return Vector3D(-x,-y,-z);}
    friend float operator*(const Vector3D&,const Vector3D&);
    friend Vector3D operator*(const Vector3D&,float);
    friend Vector3D operator*(float,const Vector3D&);
    friend ostream& operator<<(ostream&,const Vector3D&);
    friend istream& operator>>(istream&,Vector3D&);
    operator float()const{return sqrt(x*x+y*y+z*z);}
};
float operator*(const Vector3D&a,const Vector3D&b){return a.x*b.x+a.y*b.y+a.z*b.z;}
Vector3D operator*(const Vector3D&v,float s){return Vector3D(v.x*s,v.y*s,v.z*s);}
Vector3D operator*(float s,const Vector3D&v){return Vector3D(v.x*s,v.y*s,v.z*s);}
ostream& operator<<(ostream&out,const Vector3D&v){return out<<"("<<v.x<<", "<<v.y<<", "<<v.z<<")";}
istream& operator>>(istream&in,Vector3D&v){in>>v.x>>v.y>>v.z;return in;}

int main(){
    Vector3D a,b;
    cout<<"Enter x y z for Vector 1: ";cin>>a;
    cout<<"Enter x y z for Vector 2: ";cin>>b;
    cout<<"\nA="<<a<<"\nB="<<b<<"\nA+B="<<a+b<<"\nA-B="<<a-b<<"\n-A="<<-a<<endl;
    cout<<"A dot B="<<a*b<<"\nA*2="<<a*2.0f<<"\n2*A="<<2.0f*a<<endl;
    float magnitude=a; cout<<"Magnitude of A="<<magnitude<<endl;
    Vector3D c(5.0f); cout<<"Vector from scalar 5="<<c<<endl;
    system("pause"); return 0;
}