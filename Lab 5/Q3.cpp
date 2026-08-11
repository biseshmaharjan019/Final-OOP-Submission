#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;
public:
    Celsius(float c=0):temp(c){}
    operator float() const {return temp;}
    operator Fahrenheit() const;
    friend ostream& operator<<(ostream&,const Celsius&);
};

class Fahrenheit {
    float temp;
public:
    Fahrenheit(float f=0):temp(f){}
    Fahrenheit(Celsius c):temp((float)c*9/5+32){}
    friend ostream& operator<<(ostream&,const Fahrenheit&);
};

Celsius::operator Fahrenheit() const {return Fahrenheit(temp*9/5+32);}
ostream& operator<<(ostream& out,const Celsius& c){return out<<c.temp<<" C";}
ostream& operator<<(ostream& out,const Fahrenheit& f){return out<<f.temp<<" F";}

int main(){
    Celsius c=25.0;
    float value=c;
    Fahrenheit f=c;
    cout<<"Celsius: "<<c<<"\nExtracted float: "<<value<<"\nFahrenheit: "<<f<<endl;
    Celsius c2(100); Fahrenheit f2(c2);
    cout<<c2<<" = "<<f2<<endl;
    system("pause"); return 0;
}