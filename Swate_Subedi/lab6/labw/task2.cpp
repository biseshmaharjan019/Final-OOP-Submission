#include <iostream>
using namespace std;

class V {
private:
    string m;
    int y;

public:
    V(string mk, int yr) : m(mk), y(yr) {}
    void show() const { cout << "Make: " << m << "\nYear: " << y << endl; }
};

class C : public V {
private:
    int d;

public:
    C(string mk, int yr, int doors) : V(mk, yr), d(doors) {}
    void show() const {
        V::show();
        cout << "Doors: " << d << endl;
    }
};

class E : public C {
private:
    float b;
    int r;

public:
    E(string mk, int yr, int doors, float bat, int range) : C(mk, yr, doors), b(bat), r(range) {}
    void show() const {
        C::show();
        cout << "Battery: " << b << " kWh\nRange: " << r << " km" << endl;
    }
};

int main() {
    V v("Toyota", 2020);
    C c("Honda", 2022, 4);
    E e("Tesla", 2024, 4, 75.5, 450);

    cout << "Vehicle:\n"; v.show();
    cout << "\nCar:\n"; c.show();
    cout << "\nElectric:\n"; e.show();

    return 0;
}
