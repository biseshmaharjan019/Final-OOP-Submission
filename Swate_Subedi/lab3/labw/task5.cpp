#include <iostream>
using namespace std;

class Stu {
private:
  int *p;
  int n;

public:
  Stu(int x) {
    n = x;
    p = new int[n];

    cout << "Alloc " << n << " IDs" << endl;

    for (int i = 0; i < n; i++) {
      cout << "ID " << i + 1 << ": ";
      cin >> p[i];
    }
  }

  ~Stu() {
    delete[] p;
    cout << "Mem freed" << endl;
  }

  void show() const {
    cout << "IDs: ";
    for (int i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  int n;

  cout << "No. of students: ";
  cin >> n;

  if (n <= 0) {
    cout << "Invalid" << endl;
    return 1;
  }

  Stu s(n);

  cout << "\nData:" << endl;
  s.show();

  cout << "\nEnd" << endl;

  return 0;
}
