#include <iostream>
using namespace std;

class ATM {
private:
    string n;
    float b;

public:
    static int t;
    static float m;

    ATM(string n1, float b1) {
        n = n1;
        b = b1;
    }

    void deposit(float a) {
        b += a;
        t++;
        m += a;
    }

    void withdraw(float a) {
        if (a <= b) {
            b -= a;
            t++;
            m += a;
        }
    }

    static void showStats() {
        cout << "Transactions: " << t << endl;
        cout << "Money Moved: " << m << endl;
    }
};

int ATM::t = 0;
float ATM::m = 0;

int main() {
    ATM a("Ram", 5000);
    ATM b("Hari", 3000);

    a.deposit(1000);
    a.withdraw(500);

    b.deposit(2000);
    b.withdraw(1000);

    ATM::showStats();

    return 0;
}