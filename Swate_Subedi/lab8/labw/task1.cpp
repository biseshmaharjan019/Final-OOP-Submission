#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream in("source.txt");
    ofstream out("destination.txt");
    
    if (!in || !out) {
        cout << "Error\n";
        return 1;
    }
    
    char c;
    while (in.get(c))
        out.put(toupper(c));
    
    in.close();
    out.close();
    cout << "Done\n";
    return 0;
}
