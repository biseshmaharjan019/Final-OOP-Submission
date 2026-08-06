// C implementation

// #include <stdio.h>
//
// float perimeter(float a, float b) { return 2 * (a + b); }
//
// float area(float a, float b) { return a * b; }
//
// int sum() {
//   int s;
//   for (int i = 0; i <= 5; i++) {
//     s = s + i;
//   }
//   return s;
// }
//
// int main() {
//   float l = 20;
//   float b = 20;
//
//   printf("Perimeter of Rectangle of length: %.2f, breadth: %.2f is : %.2f\n",
//   l,
//          b, perimeter(l, b));
//   printf("Area of Rectangle of length: %.2f, breadth: %.2f is : %.2f\n", l,
//   b,
//          area(l, b));
//   printf("Sum = %d", sum());
//   return 0;
// }

// C++ implementation

#include <iostream>

float perimeter(float a, float b) { return 2 * (a + b); }
float area(float a, float b) { return a * b; }
int sum() {
  int s;
  for (int i = 0; i <= 5; i++) {
    s = s + i;
  }
  return s;
}

int main() {
  float l, b;

  std::cout << "Enter length: ";
  std::cin >> l;
  std::cout << "Enter breadth: ";
  std::cin >> b;

  std::cout << "Perimeter of Rectangle of length " << l << " and breadth " << b
            << " is " << perimeter(l, b) << std::endl;
  std::cout << "Area of Rectangle of length " << l << " and breadth " << b
            << " is " << area(l, b) << std::endl;
  std::cout << "Sum is: " << sum() << std::endl;
}
