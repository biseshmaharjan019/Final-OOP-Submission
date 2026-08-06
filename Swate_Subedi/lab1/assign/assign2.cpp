// C implementation

// #include <iostream>
// using namespace std;
//
// void swap(int &a, int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
//
// int main()
// {
//     int x, y;
//
//     cout << "Enter two numbers: ";
//     cin >> x >> y;
//
//     cout << "Before swapping: x = " << x << ", y = " << y << endl;
//
//     swap(x, y);
//
//     cout << "After swapping: x = " << x << ", y = " << y << endl;
//
//     return 0;
// }

// C++ implementation

#include <iostream>
using namespace std;

int is_prime(int n) {
  if (n <= 1)
    return 0;

  for (int i = 2; i < n; i++) {
    if (n % i == 0)
      return 0;
  }

  return 1;
}

int main() {
  int num;

  cout << "Enter a number: ";
  cin >> num;

  if (is_prime(num))
    cout << num << " is a prime number." << endl;
  else
    cout << num << " is not a prime number." << endl;

  return 0;
}
