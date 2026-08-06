#include<iostream>
using namespace std;
struct Patient
{
	string name;
	int age;
	string disease;
};
int main()
{
	Patient P[3];
	int i;
	cout << "Enter the detail of patients:" << endl;
	for(i=0;i<3;i++)
	{
		cout << "\nEnter name: ";
		cin >> P[i].name;
		cout << "Enter age: ";
		cin >> P[i].age;
		cout << "Enter disease: ";
		cin >> P[i].disease;
	}
	cout << "\nPATIENT DETAILS:" << endl;
	for(i=0;i<3;i++)
	{
		cout << "\nPatient " << i+1 << endl;
		cout << "Name: " << P[i].name << endl;
		cout << "Age: " << P[i].age << endl;
		cout << "Disease: " << P[i].disease << endl;
	}
	return 0;
}
