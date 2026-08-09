#include <iostream>
#include <cmath>
using namespace std;
class Vector3D {
private:
    float x,y,z;

public:
    Vector3D(float v=0) {
        x=y=z=v;
    }
    Vector3D(float a,float b,float c) {
        x=a;
        y=b;
        z=c;
    }
    Vector3D operator+(const Vector3D& v) {
        return Vector3D(x+v.x,y+v.y,z+v.z);
    }
    Vector3D operator-(const Vector3D& v) {
        return Vector3D(x-v.x,y-v.y,z-v.z);
    }
    Vector3D operator-() {
        return Vector3D(-x,-y,-z);
    }
    operator float() const {
        return sqrt(x*x+y*y+z*z);
    }
    friend float operator*(const Vector3D&,const Vector3D&);
    friend Vector3D operator*(const Vector3D&,float);
    friend Vector3D operator*(float,const Vector3D&);
    friend ostream& operator<<(ostream&,const Vector3D&);
    friend istream& operator>>(istream&,Vector3D&);
};
float operator*(const Vector3D& a,const Vector3D& b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

Vector3D operator*(const Vector3D& v,float s){
    return Vector3D(v.x*s,v.y*s,v.z*s);
}
Vector3D operator*(float s,const Vector3D& v){
    return v*s;
}
istream& operator>>(istream& in,Vector3D& v){
    in>>v.x>>v.y>>v.z;
    return in;
}
ostream& operator<<(ostream& out,const Vector3D& v){
    out<<"("<<v.x<<", "<<v.y<<", "<<v.z<<")";
    return out;
}
int main(){
    Vector3D v1,v2;
    cout<<"Enter vector1 (x y z): ";
    cin>>v1;
    cout<<"Enter vector2 (x y z): ";
    cin>>v2;
    cout<<"v1 + v2 = "<<v1+v2<<endl;
    cout<<"v1 - v2 = "<<v1-v2<<endl;
    cout<<"Dot Product = "<<v1*v2<<endl;
    cout<<"v1 * 2 = "<<v1*2<<endl;
    cout<<"3 * v2 = "<<3*v2<<endl;
    cout<<"-v1 = "<<-v1<<endl;
    float mag = v1;
    cout<<"Magnitude of v1 = "<<mag<<endl;
    Vector3D v3 = 5.0;
    cout<<"Vector from float = "<<v3<<endl;
    return 0;
}
