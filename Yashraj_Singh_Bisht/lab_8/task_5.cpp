#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream infile("source.txt");
    ofstream outfile("destination.txt");
    
    if (!infile || !outfile) {
        cout << "Error opening files." << endl;
        return 1;
    }
    
    char ch;
    while (infile.get(ch)) {
        outfile.put(toupper(ch));
    }
    
    infile.close();
    outfile.close();
    cout << "File copied and converted successfully." << endl;
    return 0;
}
