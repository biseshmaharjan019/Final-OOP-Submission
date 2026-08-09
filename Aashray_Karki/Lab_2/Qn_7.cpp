// Assignment 3: Define a structure Expense with fields description, amount, and category.
// Use addExpense() to add expenses and totalByCategory() to calculate total expenses
// for a specific category.

#include <iostream>
#include <string>
using namespace std;

struct Expense {
    string description;
    float amount;
    string category;
};

void addExpense(Expense expenses[], int &count) {
    cout << "\nEnter expense description: ";
    cin >> ws;
    getline(cin, expenses[count].description);

    cout << "Enter amount: ";
    cin >> expenses[count].amount;

    cout << "Enter category: ";
    cin >> ws;
    getline(cin, expenses[count].category);

    count++;
}

float totalByCategory(Expense expenses[], int count, string category) {
    float total = 0;

    for (int i = 0; i < count; i++) {
        if (expenses[i].category == category) {
            total = total + expenses[i].amount;
        }
    }

    return total;
}

int main() {
    Expense expenses[5];
    int count = 0;
    string category;

    cout << "Enter 5 expenses:" << endl;

    for (int i = 0; i < 5; i++) {
        addExpense(expenses, count);
    }

    cout << "\nEnter category to calculate total: ";
    cin >> ws;
    getline(cin, category);

    cout << "Total expense for " << category << " = "
         << totalByCategory(expenses, count, category) << endl;

    return 0;
}