#include<iostream>
using namespace std;
class Device{
private:
    float powerConsumption;
public:
    Device(float p){
        powerConsumption=p;
    }
    virtual void operate()=0;
    void showPower(){
        cout << "Power Consumption = " <<powerConsumption <<" W" <<endl;
    }
};
class Printer: virtual public Device{
protected:
    int printSpeed;
public:
    Printer(float p,int s):Device(p){
        printSpeed=s;
    }
    void operate(){
        cout << "Printer is printing at " <<printSpeed <<" pages/min." <<endl;
    }
};
class Scanner: virtual public Device{
protected:
    int scanResolution;
public:
    Scanner(float p,int r):Device(p){
        scanResolution=r;
    }
    void operate(){
        cout << "Scanner is scanning at " <<scanResolution <<" DPI." <<endl;
    }
};
class Photocopier: public Printer, public Scanner{
public:
    Photocopier(float p,int s,int r):Device(p), Printer(p,s), Scanner(p,r)
    {
    }
    void operate(){
        cout << "Photocopier Operation: " <<endl;
        Printer::operate();
        Scanner::operate();
    }
};
int main()
{
    Device *ptr;
    Photocopier pc(250,30,1200);
    ptr=&pc;
    ptr->operate();
    ptr->showPower();
    return 0;
}
