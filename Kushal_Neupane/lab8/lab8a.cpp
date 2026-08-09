#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ofstream fin1;
    fin1.open("read.txt");
    fin1 << "hello";
    fin1.close();

    ifstream fin;
    fin.open("read.txt");

    ofstream fout;
    fout.open("write.txt");

    if (!fin) {
        cout << "Error opening the input file!" << endl;
        return 1;
    }

    if (!fout) {
        cout << "Error opening the output file!" << endl;
        return 1;
    }

    char ch;
    while (fin.get(ch)) {
        fout.put(toupper(ch));
    }

    fin.close();
    fout.close();

    return 0;
}