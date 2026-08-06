#include <iostream>
using namespace std;

class E {
public:
    virtual float calc() const = 0;
    virtual void show() const = 0;
    virtual ~E() {}
};

class F : public E {
private:
    float s;
public:
    F(float sal) : s(sal) {}
    float calc() const override { return s; }
    void show() const override {
        cout << "Full Time: " << calc() << endl;
    }
};

class P : public E {
private:
    int h;
    float r;
public:
    P(int hours, float rate) : h(hours), r(rate) {}
    float calc() const override { return h * r; }
    void show() const override {
        cout << "Part Time: " << calc() << endl;
    }
};

class C : public E {
private:
    float f, t;
public:
    C(float fee, float tax) : f(fee), t(tax) {}
    float calc() const override { return f - (f * t / 100); }
    void show() const override {
        cout << "Contractor: " << calc() << endl;
    }
};

int main() {
    E* e[3];
    e[0] = new F(50000);
    e[1] = new P(80, 500);
    e[2] = new C(60000, 10);

    for (int i = 0; i < 3; i++) {
        e[i]->show();
        delete e[i];
    }

    return 0;
}
