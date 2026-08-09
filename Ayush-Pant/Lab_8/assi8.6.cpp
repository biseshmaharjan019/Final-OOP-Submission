#include <iostream>
using namespace std;

class Device
{
protected:
    float powerConsumption;

public:
    Device(float p)
    {
        powerConsumption = p;
    }

    virtual void operate() = 0;

    void displayPower()
    {
        cout << "Power Consumption: " << powerConsumption << " W" << endl;
    }
};

class Printer : virtual public Device
{
public:
    Printer(float p) : Device(p) {}

    void operate()
    {
        cout << "Printer is printing." << endl;
    }
};

class Scanner : virtual public Device
{
public:
    Scanner(float p) : Device(p) {}

    void operate()
    {
        cout << "Scanner is scanning." << endl;
    }
};

class Photocopier : public Printer, public Scanner
{
public:
    Photocopier(float p) : Device(p), Printer(p), Scanner(p) {}

    void operate()
    {
        Printer::operate();
        Scanner::operate();
        cout << "Photocopier completed operation." << endl;
    }
};

int main()
{
    Photocopier p(150);

    Device *d = &p;

    d->operate();
    p.displayPower();

    return 0;
}
