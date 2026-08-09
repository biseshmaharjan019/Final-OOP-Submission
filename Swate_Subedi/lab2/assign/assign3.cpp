#include <iostream>
#include <string>

struct Expense {
  std::string description;
  float amount;
  std::string category;
};

void addExpense(Expense expenses[], int &count) {
  std::cout << "Enter description: ";
  std::cin.ignore();
  std::getline(std::cin, expenses[count].description);

  std::cout << "Enter amount: ";
  std::cin >> expenses[count].amount;

  std::cout << "Enter category: ";
  std::cin >> expenses[count].category;

  count++;
}

float totalByCategory(Expense expenses[], int count, std::string category) {
  float total = 0;

  for (int i = 0; i < count; i++) {
    if (expenses[i].category == category) {
      total += expenses[i].amount;
    }
  }

  return total;
}

int main() {
  Expense expenses[100];
  int count = 0;
  int n;

  std::cout << "How many expenses do you want to add? ";
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cout << "\nEnter details for expense " << i + 1 << ":\n";
    addExpense(expenses, count);
  }

  std::string category;

  std::cout << "\nEnter category to calculate total expense: ";
  std::cin >> category;

  float total = totalByCategory(expenses, count, category);

  std::cout << "Total expenses for category \"" << category << "\" = " << total
            << std::endl;

  return 0;
}
