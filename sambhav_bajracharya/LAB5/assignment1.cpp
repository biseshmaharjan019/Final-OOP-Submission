#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int data[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& m) const {
        return Matrix2x2(
            data[0][0] + m.data[0][0],
            data[0][1] + m.data[0][1],
            data[1][0] + m.data[1][0],
            data[1][1] + m.data[1][1]
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
        return Matrix2x2(-data[0][0], -data[0][1], -data[1][0], -data[1][1]);
    }

    friend bool operator==(const Matrix2x2& m1, const Matrix2x2& m2);
    friend ostream& operator<<(ostream& out, const Matrix2x2& m);
    friend istream& operator>>(istream& in, Matrix2x2& m);
};

bool operator==(const Matrix2x2& m1, const Matrix2x2& m2) {
    return (m1.data[0][0] == m2.data[0][0]) &&
           (m1.data[0][1] == m2.data[0][1]) &&
           (m1.data[1][0] == m2.data[1][0]) &&
           (m1.data[1][1] == m2.data[1][1]);
}

ostream& operator<<(ostream& out, const Matrix2x2& m) {
    out << m.data[0][0] << " " << m.data[0][1] << "\n"
        << m.data[1][0] << " " << m.data[1][1];
    return out;
}

istream& operator>>(istream& in, Matrix2x2& m) {
    in >> m.data[0][0] >> m.data[0][1] >> m.data[1][0] >> m.data[1][1];
    return in;
}

int main() {
    Matrix2x2 m1, m2;

    cout << "Enter 4 integer elements for Matrix 1 (row by row):\n";
    cin >> m1;

    cout << "Enter 4 integer elements for Matrix 2 (row by row):\n";
    cin >> m2;

    cout << "\nMatrix 1:\n" << m1 << endl;
    cout << "\nMatrix 2:\n" << m2 << endl;

    cout << "\nAddition (m1 + m2):\n" << (m1 + m2) << endl;
    cout << "\nMultiplication (m1 * m2):\n" << (m1 * m2) << endl;
    cout << "\nNegation (-m1):\n" << (-m1) << endl;

    if (m1 == m2) {
        cout << "\nMatrix 1 and Matrix 2 are equal." << endl;
    } else {
        cout << "\nMatrix 1 and Matrix 2 are not equal." << endl;
    }

    return 0;
}
