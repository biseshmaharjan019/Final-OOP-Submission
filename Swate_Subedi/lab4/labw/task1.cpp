#include <iostream>
#include <string>

using namespace std;

class A {
private:
  string n;
  float b;

  static int t;
  static float m;

public:
  A(string x, float y) {
    n = x;
    b = y;
  }

  void d(float a) {
    if (a > 0) {
      b += a;
      t++;
      m += a;
      cout << n << " deposited: " << a << endl;
    } else {
      cout << "Error: Invalid deposit." << endl;
    }
  }

  void w(float a) {
    if (a > 0 && a <= b) {
      b -= a;
      t++;
      m += a;
      cout << n << " withdrew: " << a << endl;
    } else {
      cout << n << " tried to withdraw " << a << " but failed." << endl;
    }
  }

  void s() { cout << n << " has a balance of: " << b << endl; }

  static void st() {
    cout << "\n=== ATM STATS ===" << endl;
    cout << "Total Transactions: " << t << endl;
    cout << "Total Money Moved: " << m << endl;
    cout << "=================\n" << endl;
  }
};

int A::t = 0;
float A::m = 0.0;

int main() {
  A u1("ramu", 1000);
  A u2("shayamu", 500);

  u1.s();
  u2.s();
  cout << endl;

  u1.d(200);
  u1.w(150);

  u2.d(300);
  u2.w(50);

  cout << endl;

  u1.s();
  u2.s();

  A::st();

  return 0;
}
