#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class S {
public:
    int r;
    char n[30];
    float m;
};

int main() {
    ofstream o("students.dat", ios::binary);
    S arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i].r = i + 1;
        strcpy(arr[i].n, "Student");
        arr[i].m = 70.0 + i;
    }
    o.write((char*)&arr, sizeof(arr));
    o.close();

    fstream f("students.dat", ios::in | ios::out | ios::binary);
    int target;
    cout << "Enter roll: ";
    cin >> target;

    S t;
    bool found = false;
    while (f.read((char*)&t, sizeof(S))) {
        if (t.r == target) {
            cout << "Name: " << t.n << ", Marks: " << t.m << endl;
            cout << "New marks: ";
            cin >> t.m;

            int pos = (int)f.tellg() - sizeof(S);
            f.seekp(pos);
            f.write((char*)&t, sizeof(S));
            found = true;
            break;
        }
    }

    cout << (found ? "Updated" : "Not found") << endl;
    f.close();
    return 0;
}
