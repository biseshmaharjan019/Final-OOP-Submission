#include <iostream>
#include <typeinfo>
using namespace std;

class V {
public:
    virtual string t() const { return "Vehicle"; }
    virtual ~V() { cout << "V dtor\n"; }
};

class C : public V {
private:
    int d;
public:
    C(int doors) : d(doors) {}
    string t() const override { return "Car"; }
    int getD() const { return d; }
    ~C() override { cout << "C dtor\n"; }
};

class T : public V {
private:
    float p;
public:
    T(float payload) : p(payload) {}
    string t() const override { return "Truck"; }
    float getP() const { return p; }
    ~T() override { cout << "T dtor\n"; }
};

int main() {
    V* arr[3];
    arr[0] = new V();
    arr[1] = new C(4);
    arr[2] = new T(8.5);

    for (int i = 0; i < 3; i++) {
        cout << "\nObj " << i+1 << "\n";
        cout << "Type: " << arr[i]->t() << "\n";
        cout << "typeid: " << typeid(*arr[i]).name() << "\n";

        C* c = dynamic_cast<C*>(arr[i]);
        if (c) cout << "Doors: " << c->getD() << "\n";
        else cout << "Not Car\n";

        T* t = dynamic_cast<T*>(arr[i]);
        if (t) cout << "Payload: " << t->getP() << " tons\n";
        else cout << "Not Truck\n";

        cout << "Deleting:\n";
        delete arr[i];
    }

    return 0;
}
