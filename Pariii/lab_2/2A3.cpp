#include <iostream>
#include <string>
using namespace std;

struct Expense
{
    string description, category;
    double amount;
};

void addExpense(Expense e[], int &n)
{
    cout << "Description: ";
    getline(cin >> ws, e[n].description);

    cout << "Amount: ";
    cin >> e[n].amount;

    cout << "Category: ";
    getline(cin >> ws, e[n].category);

    n++;
}

double totalByCategory(Expense e[], int n, string cat)
{
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i].category == cat)
        {
            total += e[i].amount;
        }
    }
    return total;
}

int main()
{
    Expense e[100];
    int n = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nExpense " << i + 1 << ":\n";
        addExpense(e, n);
    }

    string cat;
    cout << "\nEnter category to total: ";
    getline(cin >> ws, cat);

    cout << "Total for " << cat << ": " << totalByCategory(e, n, cat) << "\n";

    return 0;
}