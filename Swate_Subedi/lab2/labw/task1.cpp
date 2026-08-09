#include <iostream>

int main() {
  int amt[7];
  int sum = 0;

  for (int i = 0; i < 7; i++) {
    std::cout << "Enter daily amt for day " << i + 1 << std::endl;
    std::cin >> amt[i];
  }
  for (int i = 0; i < 7; i++) {
    sum += amt[i];
  }
  std::cout << "Average of daily amt = " << sum / 7 << std::endl;
  std::cout << "Total of daily amt = " << sum << std::endl;
}
