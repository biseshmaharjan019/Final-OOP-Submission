#include <iostream>
using namespace std;

class Device {
protected:
    float powerConsumption;
public:
    Device(float power) : powerConsumption(power) {}
    virtual void operate() = 0;
    float getPowerConsumption() const {
        return powerConsumption;
    }
    virtual ~Device() {}
};

class Printer : virtual public Device {
private:
    int printPages;
public:
    Printer(float power, int pages) : Device(power), printPages(pages) {}
    void operate() override {
        cout << "Printer operating..." << endl;
    }
};

class Scanner : virtual public Device {
private:
    int resolution;
public:
    Scanner(float power, int res) : Device(power), resolution(res) {}
    void operate() override {
        cout << "Scanner operating..." << endl;
    }
};

class Photocopier : public Printer, public Scanner {
public:
    Photocopier(float power, int pages, int res)
        : Device(power), Printer(power, pages), Scanner(power, res) {}

    void operate() override {
        Printer::operate();
        Scanner::operate();
        cout << "Photocopier operating..." << endl;
    }
};

int main() {
    Photocopier copier(250.5f, 30, 1200);
    Device* devPtr = &copier;

    devPtr->operate();
    cout << "Power Consumption: " << devPtr->getPowerConsumption() << " W" << endl;

    return 0;
}