#include <iostream>
#include <string>

struct Item {
  std::string name;
  double price;
};

double calculateBill(Item i) {
  double tax = i.price * 0.10;
  return i.price + tax;
}

int main() {
  Item item1 = {"Laptop", 50000};

  double totalBill = calculateBill(item1);

  std::cout << "Item: " << item1.name << std::endl;
  std::cout << "Price: " << item1.price << std::endl;
  std::cout << "Total bill with 10% tax: " << totalBill << std::endl;

  return 0;
}
