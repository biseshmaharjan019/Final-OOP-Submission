#include <iostream>
using namespace std;
class Matrix2x2 {
private:
    int data[2][2];
public:
    Matrix2x2() {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                data[i][j]=0;
    }
    Matrix2x2 operator+(const Matrix2x2& m) {
        Matrix2x2 result;

        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                result.data[i][j]=data[i][j]+m.data[i][j];
        return result;
    }
    Matrix2x2 operator*(const Matrix2x2& m) {
        Matrix2x2 result;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++) {
                result.data[i][j]=0;
                for(int k=0;k<2;k++)
                    result.data[i][j]+=data[i][k]*m.data[k][j];
            }
        return result;
    }
    Matrix2x2 operator-() {
        Matrix2x2 result;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                result.data[i][j]=-data[i][j];
        return result;
    }
    friend bool operator==(const Matrix2x2&, const Matrix2x2&);
    friend ostream& operator<<(ostream&, const Matrix2x2&);
    friend istream& operator>>(istream&, Matrix2x2&);
};
bool operator==(const Matrix2x2& a, const Matrix2x2& b) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(a.data[i][j]!=b.data[i][j])
                return false;
    return true;
}
istream& operator>>(istream& in, Matrix2x2& m) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            in>>m.data[i][j];

    return in;
}
ostream& operator<<(ostream& out, const Matrix2x2& m) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            out<<m.data[i][j]<<" ";
        out<<endl;
    }
    return out;
}
int main() {
    Matrix2x2 A,B;
    cout<<"Enter 4 elements of A:\n";
    cin>>A;
    cout<<"Enter 4 elements of B:\n";
    cin>>B;
    cout<<"\nA+B:\n"<<A+B;
    cout<<"\nA*B:\n"<<A*B;
    cout<<"\n-A:\n"<<-A;
    cout<<"\nEquality: "<<(A==B?"Equal":"Not Equal")<<endl;
    return 0;
}
