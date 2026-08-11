#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream source("source.txt");
    ofstream destination("destination.txt");

    if (!source || !destination) {
        cout << "Error opening file." << endl;
        system("pause");
        return 1;
    }

    char ch;

    while (source.get(ch)) {
        if (islower(static_cast<unsigned char>(ch))) {
            ch = toupper(static_cast<unsigned char>(ch));
        }
        destination.put(ch);
    }

    source.close();
    destination.close();

    cout << "File copied successfully." << endl;
    cout << "All lowercase letters were converted to uppercase." << endl;

    system("pause");
    return 0;
}
