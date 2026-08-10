#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
using namespace std;

class M {
public:
    virtual void play() const = 0;
    virtual string info() const = 0;
    virtual ~M() { cout << "M dtor\n"; }
};

class A : public M {
private:
    int d, b;
public:
    A(int dur, int bit) : d(dur), b(bit) {}
    void play() const override { cout << "Playing audio\n"; }
    string info() const override { return "Audio: " + to_string(d) + "s"; }
    int getB() const { return b; }
    ~A() override { cout << "A dtor\n"; }
};

class V : public M {
private:
    int d;
    string r;
public:
    V(int dur, string res) : d(dur), r(res) {}
    void play() const override { cout << "Playing video\n"; }
    string info() const override { return "Video: " + to_string(d) + "s"; }
    string getR() const { return r; }
    ~V() override { cout << "V dtor\n"; }
};

class I : public M {
private:
    int w, h;
public:
    I(int width, int height) : w(width), h(height) {}
    void play() const override { cout << "Displaying image\n"; }
    string info() const override { return "Image: " + to_string(w) + "x" + to_string(h); }
    ~I() override { cout << "I dtor\n"; }
};

int main() {
    vector<M*> v;
    v.push_back(new A(180, 320));
    v.push_back(new V(600, "1920x1080"));
    v.push_back(new I(800, 600));

    for (M* p : v) {
        cout << "\ntypeid: " << typeid(*p).name() << "\n";
        p->play();
        cout << p->info() << "\n";

        V* vid = dynamic_cast<V*>(p);
        if (vid) cout << "Res: " << vid->getR() << "\n";

        A* aud = dynamic_cast<A*>(p);
        if (aud) cout << "Bitrate: " << aud->getB() << " kbps\n";
    }

    cout << "\nDeleting:\n";
    for (M* p : v) delete p;
    v.clear();

    return 0;
}
