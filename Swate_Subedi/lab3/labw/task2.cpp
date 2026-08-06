#include <iostream>
using namespace std;

class time {
private:
  int d, h, m, s;

public:
  time(int a, int b, int c, int e) : d(a), h(b), m(c), s(e) {}

  void add(const time &t1, const time &t2) {
    s = t1.s + t2.s;
    m = t1.m + t2.m;
    h = t1.h + t2.h;
    d = t1.d + t2.d;

    m += s / 60;
    s %= 60;

    h += m / 60;
    m %= 60;

    d += h / 24;
    h %= 24;
  }

  void show() const {
    cout << d << " days, " << h << " hours, " << m << " mins, " << s << " secs"
         << endl;
  }
};

int main() {
  class time t1(1, 14, 45, 50);
  class time t2(0, 11, 20, 25);
  class time t3(0, 0, 0, 0);

  cout << "time 1: ";
  t1.show();

  cout << "time 2: ";
  t2.show();

  t3.add(t1, t2);

  cout << "result (time 3): ";
  t3.show();

  return 0;
}
