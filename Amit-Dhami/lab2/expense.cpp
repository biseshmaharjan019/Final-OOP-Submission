#include <iostream>
using namespace std;
struct Expense {
    string description;
    float amount;
    string category;
};
void addExpense(Expense expenses[], int &count) {
    cout << "Enter description: ";
    cin >> expenses[count].description;
cout << "Enter amount: ";
    cin >> expenses[count].amount;
cout << "Enter category: ";
    cin >> expenses[count].category;
count++;
}
float totalByCategory(Expense expenses[], int count, string category) {
    float total = 0;
for(int i = 0; i < count; i++) {
        if(expenses[i].category == category) {
            total += expenses[i].amount;
        }
    }

return total;
}
int main() {
    Expense expenses[10];
    int count = 0;
for(int i = 0; i < 5; i++) {
        addExpense(expenses, count);
    }
cout << "\nTotal Food Expense = "
         << totalByCategory(expenses, count, "Food") << endl;
cout << "Total Travel Expense = "
         << totalByCategory(expenses, count, "Travel") << endl;
cout << "Total Education Expense = "
         << totalByCategory(expenses, count, "Education") << endl;
return 0;
}
