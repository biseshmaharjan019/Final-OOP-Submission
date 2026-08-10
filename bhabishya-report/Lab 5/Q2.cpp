#include <iostream>
using namespace std;

class Distance {
    int feet; float inches;
    void normalize(){
        if(inches>=12){ feet+=(int)(inches/12); inches-=((int)(inches/12))*12; }
        if(inches<=-12){ feet-=(int)((-inches)/12); inches+=((int)((-inches)/12))*12; }
    }
public:
    Distance(int f=0,float i=0):feet(f),inches(i){normalize();}
    Distance operator-() const { return Distance(-feet,-inches); }
    Distance& operator++(){ ++inches; normalize(); return *this; }
    Distance operator++(int){ Distance temp=*this; ++inches; normalize(); return temp; }
    friend Distance operator*(const Distance&,int);
    friend Distance operator*(int,const Distance&);
    friend ostream& operator<<(ostream&,const Distance&);
};
Distance operator*(const Distance& d,int n){return Distance(d.feet*n,d.inches*n);}
Distance operator*(int n,const Distance& d){return Distance(d.feet*n,d.inches*n);}
ostream& operator<<(ostream& out,const Distance& d){return out<<d.feet<<" feet "<<d.inches<<" inches";}

int main(){
    Distance d(5,8);
    cout<<"Original: "<<d<<"\nNegation: "<<-d<<"\n";
    cout<<"Prefix ++: "<<++d<<"\n";
    cout<<"Postfix ++ (old value): "<<d++<<"\nAfter postfix: "<<d<<endl;
    cout<<"D * 3: "<<d*3<<"\n3 * D: "<<3*d<<endl;
    system("pause"); return 0;
}