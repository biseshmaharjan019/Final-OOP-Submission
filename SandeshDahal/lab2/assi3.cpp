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
    string category;

    addExpense(expenses, count);
    addExpense(expenses, count);

    cout << "Enter category to calculate total: ";
    cin >> category;

    cout << "Total Expense = " 
         << totalByCategory(expenses, count, category);

    return 0;
}