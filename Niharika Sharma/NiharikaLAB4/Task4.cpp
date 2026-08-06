#include<iostream>
using namespace std;
class Maths;
class Physics{
private:
	int marks;
public:
	Physics(int m){
		marks=m;
	}
	friend int totalMarks(Physics,Maths);
	friend bool isDistinction(Physics,Maths);
};
class Maths{
private:
	int marks;
public:
	Maths(int m){
		marks=m;
	}
	friend int totalMarks(Physics,Maths);
	friend bool isDistinction(Physics,Maths);
};
int totalMarks(Physics p,Maths m){
	return p.marks+m.marks;
}
bool isDistinction(Physics p,Maths m){
	return totalMarks(p,m)>=160;
}
int main()
{
	int p,m;
	cout << "Enter Physics marks: ";
	cin >> p;
	cout << "Enter Maths marks: ";
	cin >> m;
	Physics phy(p);
	Maths math(m);
	cout << "Total Marks = " <<totalMarks(phy,math) <<endl;
	if(isDistinction(phy,math)){
		cout << "Distinction achieved!";
	}
	else{
		cout << "No Distinction!";
	}
	return 0;
}
