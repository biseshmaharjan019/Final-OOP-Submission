#include <iostream>

float cC(float am, float r) { return am * r; }

int main() {
  int a, b;
  std::cout << "Enter amt: ";
  std::cin >> a;
  std::cout << "Enter rate: ";
  std::cin >> b;
  std::cout << "Converted amt: " << cC(a, b) << std::endl;
}
