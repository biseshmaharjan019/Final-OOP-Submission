#include <iostream>
using namespace std;

class Device {
protected:
    float powerConsumption;

public:
    Device(float power) {
        powerConsumption = power;
    }

    virtual void operate() = 0;

    float getPower() const {
        return powerConsumption;
    }

    virtual ~Device() {}
};

class Printer : virtual public Device {
public:
    Printer(float power) : Device(power) {}

    void operate() override {
        cout << "Printer is printing documents." << endl;
    }
};

class Scanner : virtual public Device {
public:
    Scanner(float power) : Device(power) {}

    void operate() override {
        cout << "Scanner is scanning documents." << endl;
    }
};

class Photocopier : public Printer, public Scanner {
public:
    Photocopier(float power) : Device(power), Printer(power), Scanner(power) {}

    void operate() override {
        Printer::operate();
        Scanner::operate();
    }
};

int main() {
    Photocopier copier(250.0f);

    Device* devicePtr = &copier;

    cout << "Executing Photocopier Operations" << endl;
    devicePtr->operate();

    cout << "\nPower Consumption: " << devicePtr->getPower() << " Watts" << endl;

    return 0;
}
