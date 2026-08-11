// Expense Manager

#include <iostream>
#include <cstdlib>
using namespace std;

struct Expense
{
    string description;
    float amount;
    string category;
};

void addExpense(Expense expenses[], int &count)
{
    cout << "Enter Description: ";
    cin >> expenses[count].description;

    cout << "Enter Amount: ";
    cin >> expenses[count].amount;

    cout << "Enter Category: ";
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
    Expense expenses[100];
    int count = 0;
    string category;

    addExpense(expenses, count);
    addExpense(expenses, count);

    cout << "Enter Category to Calculate Total: ";
    cin >> category;

    cout << "Total Expense = "
         << totalByCategory(expenses, count, category)
         << endl;

    system("pause");
    return 0;
}