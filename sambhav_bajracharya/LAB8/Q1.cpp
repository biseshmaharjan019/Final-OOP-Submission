#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream inFile("source.txt");
    ofstream outFile("destination.txt");

    if (!inFile || !outFile) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        outFile.put(toupper(ch));
    }

    inFile.close();
    outFile.close();

    cout << "File copied successfully with uppercase conversion." << endl;
    return 0;
}
