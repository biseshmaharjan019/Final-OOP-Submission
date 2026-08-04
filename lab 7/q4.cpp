#include<iostream>
using namespace std;

class Device{
public:
    float power;

    Device(float p)
    {
        power=p;
    }

    virtual void operate()=0;
};

class Printer:virtual public Device{
public:
    Printer():Device(100){}

    void operate()
    {
        cout<<"Printing..."<<endl;
    }
};

class Scanner:virtual public Device{
public:
    Scanner():Device(100){}

    void operate()
    {
        cout<<"Scanning..."<<endl;
    }
};

class Photocopier:public Printer,public Scanner{
public:
    Photocopier():Device(100){}

    void operate()
    {
        Printer::operate();
        Scanner::operate();
    }
};

int main()
{
    Photocopier p;

    Device *d=&p;

    d->operate();

    cout<<"Power = "<<p.power<<endl;

    return 0;
}