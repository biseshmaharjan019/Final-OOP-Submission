#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if (!fin) {
        cout<<"Error opening file!";
        return 1;
    }
    char ch;
    while (fin.get(ch)) {
        if (ch >= 'a' && ch <= 'z')
            ch = ch - 32;
        fout.put(ch);
    }
    fin.close();
    fout.close();
    cout << "File copied successfully";
    return 0;
}
