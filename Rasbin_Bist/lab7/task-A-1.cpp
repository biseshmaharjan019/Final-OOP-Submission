#include <iostream>
#include <string>

class Device {
protected:
    float powerConsumption;
public:
    Device(float watts) : powerConsumption(watts) {
        std::cout << "Device constructor called\n";
    }
    virtual void operate() = 0;
    float getPower() const { return powerConsumption; }
    virtual ~Device() {
        std::cout << "Device destructor called\n";
    }
};

class Printer : virtual public Device {
protected:
    int dpi;
public:
    Printer(float watts, int dpi) : Device(watts), dpi(dpi) {
        std::cout << "Printer constructor called\n";
    }
    void operate() override {
        std::cout << "Printer operating at " << dpi << " DPI\n";
    }
    ~Printer() {
        std::cout << "Printer destructor called\n";
    }
};

class Scanner : virtual public Device {
protected:
    std::string colorMode;
public:
    Scanner(float watts, std::string mode) : Device(watts), colorMode(mode) {
        std::cout << "Scanner constructor called\n";
    }
    void operate() override {
        std::cout << "Scanner operating in " << colorMode << " mode\n";
    }
    ~Scanner() {
        std::cout << "Scanner destructor called\n";
    }
};

class Photocopier : public Printer, public Scanner {
    int copySpeed;
public:
    Photocopier(float watts, int dpi, std::string mode, int speed)
        : Device(watts), Printer(watts, dpi), Scanner(watts, mode), copySpeed(speed) {
        std::cout << "Photocopier constructor called\n";
    }
    void operate() override {
        Scanner::operate();
        Printer::operate();
        std::cout << "Photocopier speed: " << copySpeed << " ppm\n";
    }
    ~Photocopier() {
        std::cout << "Photocopier destructor called\n";
    }
};

int main() {
    Photocopier pc(350.0f, 1200, "Color", 30);

    Device* d = &pc;
    d->operate();

    std::cout << "Power via Device*:  " << d->getPower() << " W\n";
    std::cout << "Power via Printer*: " << static_cast<Printer*>(&pc)->getPower() << " W\n";
    std::cout << "Power via Scanner*: " << static_cast<Scanner*>(&pc)->getPower() << " W\n";

    return 0;
}