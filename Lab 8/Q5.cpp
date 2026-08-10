#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("source.txt");
    ofstream outFile("destination.txt");

    if (!inFile || !outFile) {
        cerr << "Error opening file(s)!" << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        outFile.put(toupper(ch));
    }

    inFile.close();
    outFile.close();

    cout << "File copied and converted to uppercase successfully." << endl;
    return 0;
}