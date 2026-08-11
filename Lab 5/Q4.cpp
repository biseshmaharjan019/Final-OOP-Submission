// Matrix2x2 Class with Operator Overloading

#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix2x2
{
    int data[2][2];

public:
    Matrix2x2()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    Matrix2x2 operator+(const Matrix2x2 &m) const
    {
        Matrix2x2 r;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                r.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return r;
    }

    Matrix2x2 operator*(const Matrix2x2 &m) const
    {
        Matrix2x2 r;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    r.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return r;
    }

    Matrix2x2 operator-() const
    {
        Matrix2x2 r;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                r.data[i][j] = -data[i][j];
            }
        }
        return r;
    }

    friend bool operator==(const Matrix2x2 &, const Matrix2x2 &);
    friend ostream &operator<<(ostream &, const Matrix2x2 &);
    friend istream &operator>>(istream &, Matrix2x2 &);
};

bool operator==(const Matrix2x2 &a, const Matrix2x2 &b)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (a.data[i][j] != b.data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

ostream &operator<<(ostream &out, const Matrix2x2 &m)
{
    for (int i = 0; i < 2; i++)
    {
        out << "[ ";
        for (int j = 0; j < 2; j++)
        {
            out << m.data[i][j] << " ";
        }
        out << "]\n";
    }
    return out;
}

istream &operator>>(istream &in, Matrix2x2 &m)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            in >> m.data[i][j];
        }
    }
    return in;
}

int main()
{
    Matrix2x2 a, b;

    cout << "Enter 4 elements of Matrix 1:\n";
    cin >> a;

    cout << "Enter 4 elements of Matrix 2:\n";
    cin >> b;

    cout << "\nA:\n" << a;
    cout << "B:\n" << b;
    cout << "A+B:\n" << a + b;
    cout << "A*B:\n" << a * b;
    cout << "-A:\n" << -a;
    cout << (a == b ? "Matrices are equal." : "Matrices are not equal.") << endl;

    system("pause");
    return 0;
}