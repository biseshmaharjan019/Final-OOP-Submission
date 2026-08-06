#include <iostream>

int main() {
  int n, v;
  int seats[10] = {0};
  int s[10];
  std::cout << "Seats status :" << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << i << ": " << seats[i] << std::endl;
  }

  std::cout << "How many seats you want to book" << std::endl;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cout << "Which seat you want to book?" << std::endl;
    std::cin >> v;
    s[i] = v;
  }
  for (int i = 0; i < n; i++) {
    seats[s[i]] = 1;
  }

  std::cout << "Updated Seats status :" << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << i << ": " << seats[i] << std::endl;
  }
}
