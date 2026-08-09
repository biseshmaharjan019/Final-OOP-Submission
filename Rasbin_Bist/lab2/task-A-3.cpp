#include <iostream>
#include <string>
using namespace std;

/*
 * LAB ASSIGNMENT
 * Program     : Expense Tracker
 * Description : Add expenses and calculate total by category
 *               using structure and functions.
 */

#define MAX 100

struct Expense {
    string description;
    float amount;
    string category;
};

// Function to add an expense
void addExpense(Expense expenses[], int &count) {
    if (count >= MAX) {
        cout << "Expense list is full.\n";
        return;
    }
    cout << "Enter Description : "; cin >> expenses[count].description;
    cout << "Enter Amount      : "; cin >> expenses[count].amount;
    cout << "Enter Category    : "; cin >> expenses[count].category;
    count++;
    cout << "Expense added successfully.\n";
}

// Function to calculate total by category
float totalByCategory(Expense expenses[], int count, string category) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        if (expenses[i].category == category)
            total += expenses[i].amount;
    }
    return total;
}

// Function to display all expenses
void displayExpenses(Expense expenses[], int count) {
    if (count == 0) {
        cout << "No expenses added yet.\n";
        return;
    }
    cout << "\n--------------------------------------------\n";
    cout << "No.  Description     Amount    Category\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ".   "
             << expenses[i].description << "\t\t"
             << expenses[i].amount << "\t  "
             << expenses[i].category << endl;
    }
    cout << "--------------------------------------------\n";
}

int main() {
    Expense expenses[MAX];
    int count = 0;
    int choice;
    string category;

    do {
        cout << "\n1. Add Expense\n";
        cout << "2. Total by Category\n";
        cout << "3. Display All Expenses\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addExpense(expenses, count);
        } else if (choice == 2) {
            cout << "Enter category: ";
            cin >> category;
            float total = totalByCategory(expenses, count, category);
            cout << "Total expenses for " << category << " : " << total << endl;
        } else if (choice == 3) {
            displayExpenses(expenses, count);
        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}