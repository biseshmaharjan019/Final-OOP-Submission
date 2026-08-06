#include <iostream>
using namespace std;

class box {
private:
  float x, y, z;

public:
  box() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
    cout << "default constructor called." << endl;
  }

  box(float a, float b, float c = 0.0) {
    x = a;
    y = b;
    z = c;
    cout << "parameterized constructor" << endl;
  }

  box(const box &o) {
    x = o.x;
    y = o.y;
    z = o.z;
    cout << "copy constructor called" << endl;
  }

  ~box() { cout << "destructor called: object destroyed" << endl; }

  void show() const {
    cout << "dimensions: " << x << " x " << y << " x " << z << endl;
  }
};

int main() {
  cout << "creating object 1" << endl;
  box b1;
  b1.show();

  cout << "creating object 2" << endl;
  box b2(5.5, 4.3, 3.5);
  b2.show();

  cout << "creating object 3" << endl;
  box b3(7.3, 5.2);
  b3.show();

  cout << "creating object 4" << endl;
  box b4 = b2;
  b4.show();

  return 0;
}
