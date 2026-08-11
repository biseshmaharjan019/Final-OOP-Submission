#include <iostream>
using namespace std;

class Device {
public:
    float powerConsumption;

    Device(float pc) : powerConsumption(pc) {}

    virtual void operate() = 0;
    virtual ~Device() {}
};

class Printer : virtual public Device {
protected:
    int printSpeed;

public:
    Printer(float pc, int speed) : Device(pc), printSpeed(speed) {}

    void operate() override {
        cout << "Printer operating at " << printSpeed << " pages per minute." << endl;
    }
};

class Scanner : virtual public Device {
protected:
    int resolutionDPI;

public:
    Scanner(float pc, int dpi) : Device(pc), resolutionDPI(dpi) {}

    void operate() override {
        cout << "Scanner operating at " << resolutionDPI << " DPI resolution." << endl;
    }
};

class Photocopier : public Printer, public Scanner {
public:
    Photocopier(float pc, int speed, int dpi) 
        : Device(pc), Printer(pc, speed), Scanner(pc, dpi) {}

    void operate() override {
        cout << "--- Photocopier Combined Operation ---" << endl;
        Printer::operate();
        Scanner::operate();
    }
};

int main() {
    Photocopier copier(250.0f, 35, 1200);

    Device* devPtr = &copier;

    devPtr->operate();

    cout << "\nPower Consumption: " << devPtr->powerConsumption << " Watts" << endl;
    cout << "(Verified: Only one single instance of Device exists due to virtual inheritance)" << endl;

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}