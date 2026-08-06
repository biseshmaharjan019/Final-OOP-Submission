#include <iostream>
using namespace std;

class T {
private:
    int id;
    string s;

public:
    T(int tid, string sub) : id(tid), s(sub) {}
    void show() const {
        cout << "Teacher ID: " << id << "\nSubject: " << s << endl;
    }
};

class R {
private:
    string a;
    int p;

public:
    R(string area, int pub) : a(area), p(pub) {}
    void show() const {
        cout << "Research: " << a << "\nPublications: " << p << endl;
    }
};

class P : public T, public R {
private:
    string u;

public:
    P(int tid, string sub, string area, int pub, string uni)
        : T(tid, sub), R(area, pub), u(uni) {}

    void show() const {
        T::show();
        R::show();
        cout << "University: " << u << endl;
    }
};

int main() {
    P prof(101, "OOP", "AI", 5, "HCOE");
    cout << "Professor:\n";
    prof.show();
    return 0;
}

/*
Constructor order: Base constructors execute in declaration order
(left to right) - Teacher first, then Researcher, then Professor.
*/
