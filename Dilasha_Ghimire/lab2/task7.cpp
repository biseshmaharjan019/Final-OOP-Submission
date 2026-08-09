#include <iostream>
using namespace std;

struct Expense {
    string description;
    float amount;
    string category;
};

// Function to add expense
void addExpense(Expense expenses[], int &count) {
    cout << "Enter description: "; cin >> expenses[count].description;
    cout << "Enter amount     : "; cin >> expenses[count].amount;
    cout << "Enter category   : "; cin >> expenses[count].category;
    count++;
}

// Function to calculate total by category
float totalByCategory(Expense expenses[], int count, string category) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        if (expenses[i].category == category) {
            total += expenses[i].amount;
        }
    }
    return total;
}

int main() {
    Expense expenses[10];
    int count = 0;

    // Add 5 expenses
    for (int i = 0; i < 5; i++) {
        cout << "\nExpense " << i + 1 << ":" << endl;
        addExpense(expenses, count);
    }

    // Display totals by category
    cout << "\n===== Total by Category =====" << endl;
    cout << "Food  : " << totalByCategory(expenses, count, "Food")   << endl;
    cout << "Travel: " << totalByCategory(expenses, count, "Travel") << endl;
    cout << "Other : " << totalByCategory(expenses, count, "Other")  << endl;

    return 0;
}