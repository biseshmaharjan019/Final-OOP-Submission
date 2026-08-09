#include <iostream>
using namespace std;

class M {
private:
    int d[2][2];

public:
    M() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                d[i][j] = 0;
    }

    M operator+(const M& m) const {
        M r;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                r.d[i][j] = d[i][j] + m.d[i][j];
        return r;
    }

    M operator*(const M& m) const {
        M r;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                r.d[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    r.d[i][j] += d[i][k] * m.d[k][j];
            }
        return r;
    }

    M operator-() const {
        M r;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                r.d[i][j] = -d[i][j];
        return r;
    }

    friend bool operator==(const M& a, const M& b);
    friend istream& operator>>(istream& in, M& m);
    friend ostream& operator<<(ostream& out, const M& m);
};

bool operator==(const M& a, const M& b) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (a.d[i][j] != b.d[i][j]) return false;
    return true;
}

istream& operator>>(istream& in, M& m) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            in >> m.d[i][j];
    return in;
}

ostream& operator<<(ostream& out, const M& m) {
    for (int i = 0; i < 2; i++) {
        out << "| ";
        for (int j = 0; j < 2; j++)
            out << m.d[i][j] << " ";
        out << "|\n";
    }
    return out;
}

int main() {
    M a, b;
    cout << "Enter 4 elements of M1: ";
    cin >> a;
    cout << "Enter 4 elements of M2: ";
    cin >> b;

    cout << "\nM1:\n" << a;
    cout << "\nM2:\n" << b;
    cout << "\nSum:\n" << a + b;
    cout << "\nProduct:\n" << a * b;
    cout << "\nNeg M1:\n" << -a;
    cout << "\n" << (a == b ? "Equal" : "Not equal") << endl;

    return 0;
}
