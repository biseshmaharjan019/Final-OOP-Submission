#include <iostream>
using namespace std;
class Device
{
public:
    float powerConsumption;
    Device(float power):powerConsumption(power){}
    virtual void operate()=0;
    virtual ~Device(){}
};
class Printer : virtual public Device
{
protected:
    int printSpeed;

public:
    Printer(float power,int speed):Device(power),printSpeed(speed){}

    void operate() override
    {
        cout<<"Printing at "<<printSpeed<<" ppm"<<endl;
    }
};
class Scanner : virtual public Device
{
protected:
    int scanResolution;
public:
    Scanner(float power,int resolution):Device(power),scanResolution(resolution){}

    void operate() override
    {
        cout<<"Scanning at "<<scanResolution<<" dpi"<<endl;
    }
};
class Photocopier : public Printer,public Scanner
{
public:
    Photocopier(float power,int speed,int resolution)
        :Device(power),Printer(power,speed),Scanner(power,resolution){}

    void operate() override
    {
        Printer::operate();
        Scanner::operate();
    }
};
int main()
{
    Photocopier p(500,25,1200);
    Device* ptr=&p;
    ptr->operate();
    cout<<"Power Consumption = "<<p.powerConsumption<<endl;
    return 0;
}
