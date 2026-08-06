#include <iostream>
using namespace std;

class D {
private:
    float p;
public:
    D(float power) : p(power) {}
    float getP() const { return p; }
    virtual void op() = 0;
    virtual ~D() {}
};

class P : virtual public D {
private:
    int s;
public:
    P(float power, int speed) : D(power), s(speed) {}
    void op() override {
        cout << "Printing at " << s << " ppm\n";
    }
};

class S : virtual public D {
private:
    int r;
public:
    S(float power, int res) : D(power), r(res) {}
    void op() override {
        cout << "Scanning at " << r << " DPI\n";
    }
};

class PC : public P, public S {
public:
    PC(float power, int speed, int res)
        : D(power), P(power, speed), S(power, res) {}
    void op() override {
        cout << "Photocopier:\n";
        P::op();
        S::op();
    }
};

int main() {
    PC pc(500, 30, 1200);
    D* ptr = &pc;
    ptr->op();
    cout << "Power: " << ptr->getP() << " W\n";
    return 0;
}
