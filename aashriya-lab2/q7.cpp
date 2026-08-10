#include <iostream>
using namespace std;

struct Expense {
    string description;
    float amount;
    string category;
};

// Function to add one expense
void addExpense(Expense e[], int &count) {
    cout << "Enter Description: ";
    cin >> e[count].description;

    cout << "Enter Amount: ";
    cin >> e[count].amount;

    cout << "Enter Category: ";
    cin >> e[count].category;

    count++;
}

// Function to calculate total for a category
float totalByCategory(Expense e[], int count, string category) {
    float total = 0;

    for(int i = 0; i < count; i++) {
        if(e[i].category == category) {
            total = total + e[i].amount;
        }
    }

    return total;
}

int main() {
    Expense e[10];
    int count = 0;
    string cat;

    // Add 3 expenses
    for(int i = 0; i < 3; i++) {
        addExpense(e, count);
    }

    cout << "\nEnter category to find total: ";
    cin >> cat;

    cout << "Total Expense = "
         << totalByCategory(e, count, cat);

    return 0;
}