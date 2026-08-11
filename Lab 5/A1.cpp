#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int data[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }
    Matrix2x2 operator+(const Matrix2x2& m) const {
        return Matrix2x2(
            data[0][0] + m.data[0][0], data[0][1] + m.data[0][1],
            data[1][0] + m.data[1][0], data[1][1] + m.data[1][1]
        );
    }
    Matrix2x2 operator*(const Matrix2x2& m) const {
        return Matrix2x2(
            data[0][0] * m.data[0][0] + data[0][1] * m.data[1][0],
            data[0][0] * m.data[0][1] + data[0][1] * m.data[1][1],
            data[1][0] * m.data[0][0] + data[1][1] * m.data[1][0],
            data[1][0] * m.data[0][1] + data[1][1] * m.data[1][1]
        );
    }
    Matrix2x2 operator-() const {
        return Matrix2x2(
            -data[0][0], -data[0][1],
            -data[1][0], -data[1][1]
        );
    }
    friend bool operator==(const Matrix2x2& m1, const Matrix2x2& m2) {
        return (m1.data[0][0] == m2.data[0][0] && m1.data[0][1] == m2.data[0][1] &&
                m1.data[1][0] == m2.data[1][0] && m1.data[1][1] == m2.data[1][1]);
    }
    friend ostream& operator<<(ostream& os, const Matrix2x2& m) {
        os << m.data[0][0] << "\t" << m.data[0][1] << "\n";
        os << m.data[1][0] << "\t" << m.data[1][1];
        return os;
    }
    friend istream& operator>>(istream& is, Matrix2x2& m) {
        cout << "Enter 4 integer elements (r1c1 r1c2 r2c1 r2c2): ";
        is >> m.data[0][0] >> m.data[0][1] >> m.data[1][0] >> m.data[1][1];
        return is;
    }
};

int main() {
    Matrix2x2 m1, m2;
    cin >> m1;
    cin >> m2;

    cout << "\nMatrix 1:\n" << m1 << endl;
    cout << "\nMatrix 2:\n" << m2 << endl;

    cout << "\nAddition (m1 + m2):\n" << (m1 + m2) << endl;
    cout << "\nMultiplication (m1 * m2):\n" << (m1 * m2) << endl;
    cout << "\nNegation (-m1):\n" << (-m1) << endl;

    if (m1 == m2) {
        cout << "\nMatrices m1 and m2 are equal." << endl;
    } else {
        cout << "\nMatrices m1 and m2 are not equal." << endl;
    }

    return 0;
}