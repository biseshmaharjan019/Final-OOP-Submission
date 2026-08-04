#include <iostream>
using namespace std;

class Matrix2x2
{
private:
    int data[2][2];

public:
    // Input
    friend istream& operator>>(istream &in, Matrix2x2 &m)
    {
        cout << "Enter 4 elements: ";
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                in >> m.data[i][j];
        return in;
    }

    // Output
    friend ostream& operator<<(ostream &out, const Matrix2x2 &m)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                out << m.data[i][j] << " ";
            out << endl;
        }
        return out;
    }

    // Matrix Addition
    Matrix2x2 operator+(const Matrix2x2 &m)
    {
        Matrix2x2 temp;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                temp.data[i][j] = data[i][j] + m.data[i][j];
        return temp;
    }

    // Matrix Multiplication
    Matrix2x2 operator*(const Matrix2x2 &m)
    {
        Matrix2x2 temp;

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                temp.data[i][j] = 0;
                for(int k=0;k<2;k++)
                    temp.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
        return temp;
    }

    // Unary Minus
    Matrix2x2 operator-()
    {
        Matrix2x2 temp;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                temp.data[i][j] = -data[i][j];
        return temp;
    }

    // Equality
    friend bool operator==(const Matrix2x2 &a,const Matrix2x2 &b)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(a.data[i][j] != b.data[i][j])
                    return false;
        return true;
    }
};

int main()
{
    Matrix2x2 A, B;

    cin >> A;
    cin >> B;

    cout << "\nMatrix A:\n" << A;
    cout << "\nMatrix B:\n" << B;

    cout << "\nA + B:\n" << A + B;

    cout << "\nA * B:\n" << A * B;

    cout << "\n-A:\n" << -A;

    if(A == B)
        cout << "\nMatrices are Equal";
    else
        cout << "\nMatrices are Not Equal";

    return 0;
}