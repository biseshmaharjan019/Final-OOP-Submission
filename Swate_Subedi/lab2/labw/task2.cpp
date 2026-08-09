#include <iostream>

struct Patient {
  std::string name;
  int age;
  std::string disease;
};

int main() {
  Patient p[3];

  for (int i = 0; i < 3; i++) {
    std::cout << "Enter name of patient " << i + 1 << std::endl;
    std::cin >> p[i].name;
    std::cout << "Enter age of patient " << i + 1 << std::endl;
    std::cin >> p[i].age;
    std::cout << "Enter disease of patient " << i + 1 << std::endl;
    std::cin >> p[i].disease;
    std::cout << std::endl;
  }
  for (int i = 0; i < 3; i++) {
    std::cout << "Name of patient " << p[i].name << std::endl;
    std::cout << "Age of patient " << p[i].age << std::endl;
    std::cout << "Disease of patient " << p[i].disease << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
