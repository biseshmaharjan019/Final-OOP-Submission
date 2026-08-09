#include <iostream>
#include <string>

struct Product {
  std::string name;
  int code;
  float price;
  int quantity;
};

int main() {
  Product p[5];

  for (int i = 0; i < 5; i++) {
    std::cout << "Enter details for Product " << i + 1 << std::endl;

    std::cout << "Name: ";
    std::cin >> p[i].name;

    std::cout << "Code: ";
    std::cin >> p[i].code;

    std::cout << "Price: ";
    std::cin >> p[i].price;

    std::cout << "Quantity: ";
    std::cin >> p[i].quantity;

    std::cout << std::endl;
  }

  std::cout << "Products with quantity less than 10:" << std::endl;

  for (int i = 0; i < 5; i++) {
    if (p[i].quantity < 10) {
      std::cout << "\nProduct Name: " << p[i].name << std::endl;
      std::cout << "Code: " << p[i].code << std::endl;
      std::cout << "Price: " << p[i].price << std::endl;
      std::cout << "Quantity: " << p[i].quantity << std::endl;
    }
  }
  return 0;
}
