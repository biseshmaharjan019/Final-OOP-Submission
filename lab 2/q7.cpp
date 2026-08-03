#include <iostream>
using namespace std;

struct Expense
{
    string description;
    float amount;
    string category;
};

void addExpense(Expense expenses[], int &count)
{
    cout << "\nExpense " << count + 1 << endl;

    cout << "Description: ";
    cin >> expenses[count].description;

    cout << "Amount: ";
    cin >> expenses[count].amount;

    cout << "Category: ";
    cin >> expenses[count].category;

    count++;
}

float totalByCategory(Expense expenses[], int count, string category)
{
    float total = 0;

    for(int i = 0; i < count; i++)
    {
        if(expenses[i].category == category)
        {
            total += expenses[i].amount;
        }
    }

    return total;
}

int main()
{
    Expense expenses[10];
    int count = 0;

    for(int i = 0; i < 5; i++)
    {
        addExpense(expenses, count);
    }

    cout << "\nTotal Food Expense = "
         << totalByCategory(expenses, count, "Food") << endl;

    cout << "Total Travel Expense = "
         << totalByCategory(expenses, count, "Travel") << endl;

    cout << "Total Shopping Expense = "
         << totalByCategory(expenses, count, "Shopping") << endl;

    return 0;
}
