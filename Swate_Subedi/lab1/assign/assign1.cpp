// C implementation

// #include <stdio.h>
//
// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
//
// int main()
// {
//     int x, y;
//
//     printf("Enter two numbers: ");
//     scanf("%d %d", &x, &y);
//
//     printf("Before swapping: x = %d, y = %d\n", x, y);
//
//     swap(&x, &y);
//
//     printf("After swapping: x = %d, y = %d\n", x, y);
//
//     return 0;
// }

// C++ implementation
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int main() {
  int x, y;

  cout << "Enter two numbers: ";
  cin >> x >> y;

  cout << "Before swapping: x = " << x << ", y = " << y << endl;

  swap(x, y);

  cout << "After swapping: x = " << x << ", y = " << y << endl;

  return 0;
}
