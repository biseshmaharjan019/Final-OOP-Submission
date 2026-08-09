#include <iostream>
using namespace std;

class C {
private:
  float r;

public:
  C(float x) { r = x; }

  void s(float x) { r = x; }

  float a() const { return 3.14159f * r * r; }

  float c() const { return 2 * 3.14159f * r; }

  void d() const {
    cout << "Radius: " << r << ", Area: " << a() << ", Circumference: " << c()
         << endl;
  }
};

int main() {
  C n(5.0f);

  cout << "--- Normal Object Calls ---" << endl;
  n.s(7.0f);
  n.d();

  const C k(10.0f);

  cout << "\n--- Const Object Calls ---" << endl;
  k.d();

  return 0;
}
