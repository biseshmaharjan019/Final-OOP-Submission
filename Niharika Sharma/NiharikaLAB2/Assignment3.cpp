#include<iostream>
#include<string>
using namespace std;
struct Expense
{
	string description;
	int amount;
	string category;
};
void addExpense(Expense expenses[], int &count)
{
	cout << "\nEnter Expense " << count+1 << " Details:\n";
    cout << "Description: ";
    cin >> expenses[count].description;
    cout << "Amount: ";
    cin >> expenses[count].amount;
    cout << "Category: ";
    cin >> expenses[count].category;
    count++;
}
float totalByCategory(Expense expenses[],int count,string category)
{
    float total=0;
    for(int i=0;i<count;i++)
    {
        if(expenses[i].category==category)
        {
            total+=expenses[i].amount;
        }
    }
    return total;
}
int main()
{
	Expense expenses[10];
    int count=0;
    for(int i=0;i<5;i++)
    {
        addExpense(expenses,count);
    }

    cout << "\nCategory Totals:\n";
    cout << "Food: " << totalByCategory(expenses,count,"Food") <<endl;
    cout << "Travel: " << totalByCategory(expenses,count,"Travel") <<endl;
    cout << "Shopping: " << totalByCategory(expenses,count,"Shopping") <<endl;
    cout << "Bills: " << totalByCategory(expenses,count,"Bills") <<endl;
    return 0;
}
