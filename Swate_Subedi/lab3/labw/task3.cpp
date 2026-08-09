#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
  int a;
  string s;
  float b;

public:
  BankAccount() {
    a = 0;
    s = "U";
    b = 0.0f;
    cout << "Default constructor called" << endl;
  }

  BankAccount(int x, string y, float z) {
    a = x;
    s = y;
    b = z;
    cout << "Parameterized constructor called" << endl;
  }

  ~BankAccount() { cout << "Destructor called" << endl; }

  void dep(float x) {
    if (x > 0) {
      b += x;
      cout << "Dep: " << x << " Bal: " << b << endl;
    }
  }

  void wd(float x) {
    if (x > b) {
      cout << "No balance" << endl;
    } else if (x > 0) {
      b -= x;
      cout << "Wd: " << x << " Bal: " << b << endl;
    }
  }

  void show() const {
    cout << "A/C: " << a << " N: " << s << " B: " << b << endl;
  }
};

int main() {
  BankAccount a1;
  a1.show();

  BankAccount a2(101, "Raj", 500.0f);
  a2.show();

  a2.dep(150.5f);
  a2.wd(100.0f);
  a2.wd(600.0f);

  return 0;
}
