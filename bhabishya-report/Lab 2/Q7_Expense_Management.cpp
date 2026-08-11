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
            total += expenses[i].amount;
        }
    }

    return total;
}

int main() {
    Expense expenses[100];
    int count = 0;
    int n;
    string category;

    cout << "How many expenses do you want to add? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        addExpense(expenses, count);
    }

    cout << "\nEnter category to calculate total: ";
    cin >> ws;
    getline(cin, category);

    cout << "Total expenses for " << category << " = "
         << totalByCategory(expenses, count, category) << endl;
system("pause");
    return 0;
}
