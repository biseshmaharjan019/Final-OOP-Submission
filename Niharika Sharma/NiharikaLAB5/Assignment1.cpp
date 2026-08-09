#include<iostream>
using namespace std;
class Matrix{
private:
	int a[2][2];
public:
	void input(){
		cout << "Enter the elements of the matrix:\n";
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				cin >> a[i][j];
			}
		}
	}
	void display(){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				cout << a[i][j] <<" ";
			}
			cout <<endl;
		}
	}
	Matrix operator+(Matrix m){
		Matrix temp;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				temp.a[i][j]=a[i][j]+m.a[i][j];
			}
		}
		return temp;
	}
	Matrix operator*(Matrix m){
		Matrix temp;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				temp.a[i][j]=0;
				for(int k=0;k<2;k++){
					temp.a[i][j]+=a[i][k]*m.a[k][j];
				}
			}
		}
		return temp;
	}
};
int main()
{
	Matrix m1,m2,sum,product;
	cout << "Enter first matrix:\n";
	m1.input();
	cout << "\nEnter second matrix:\n";
	m2.input();
	sum=m1+m2;
	product=m1*m2;
	cout << "\n1st Matrix:\n";
	m1.display();
	cout << "\n2nd Matrix:\n";
	m2.display();
	cout << "\nSum of Matrices:\n";
	sum.display();
	cout << "\nProduct of Matrices:\n";
	product.display();
	return 0;
}
