#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("source.txt");
    ofstream fout("destination.txt");

    if (!fin || !fout) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char ch;
    while (fin.get(ch)) {
        fout.put(toupper(ch));
    }

    fin.close();
    fout.close();
    cout << "File copied successfully with lowercase converted to uppercase." << endl;
    return 0;
}