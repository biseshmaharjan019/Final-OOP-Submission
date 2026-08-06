#include<iostream>
using namespace std;
class StudentClass{
private:
	int *studentIDs;
	int size;
public:
	StudentClass(int n){
		size=n;
		studentIDs = new int[size];
		cout << "Enter " <<size <<" student IDs: "<<endl;
		for(int i=0;i<size;i++){
			cin >> studentIDs[i];
		}
	}
	void display(){
		cout << "\nStudent IDs are: " <<endl;
		for(int i=0;i<size;i++){
			cout << studentIDs[i] <<" ";
		}
		cout <<endl;
	}
	~StudentClass(){
		delete[] studentIDs;
		cout << "Memory freed." <<endl;
	}
};
int main()
{
	int n;
	cout << "Enter the no. of students: ";
	cin >> n;
	StudentClass s(n);
	s.display();
	return 0;
}
