#include <iostream>
#include <string>
using namespace std;

class Dept {
private:
  int i;
  string n;

public:
  Dept(int a, string b) : i(a), n(b) { cout << "C: " << n << endl; }

  ~Dept() { cout << "D: " << n << endl; }
};

int main() {
  cout << "Main Start" << endl;

  Dept d1(1, "CS");

  {
    cout << "A In" << endl;
    Dept d2(2, "EE");
    cout << "A Out" << endl;
  }

  {
    cout << "B In" << endl;
    Dept d3(3, "ME");
    cout << "B Out" << endl;
  }

  cout << "Main End" << endl;

  return 0;
}
