 #include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char ch;
    if (!fin)
    {
        cout << "Cannot open input file." << endl;
        return 1;
    }
    while (fin.get(ch))
    {
        if (islower(ch))
            ch = toupper(ch);

        fout.put(ch);
    }
    cout << "File copied successfully with lowercase letters converted to uppercase." << endl;

    fin.close();
    fout.close();

    return 0;
}
