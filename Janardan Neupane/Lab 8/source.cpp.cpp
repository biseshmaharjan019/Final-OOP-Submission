#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    ifstream source("source.txt");
    ofstream target("target.txt");

    if (!source || !target)
    {
        cout << "Error opening file!";
        return 1;
    }

    char ch;

    while (source.get(ch))
    {
        if (islower(ch))
            ch = toupper(ch);

        target.put(ch);
    }

    source.close();
    target.close();

    cout << "File copied successfully.";
    return 0;
}
