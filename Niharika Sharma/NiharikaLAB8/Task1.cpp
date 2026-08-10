#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream source("source.txt");
    ofstream target("target.txt");
    char ch;
    while(source.get(ch))
    {
        if(ch>='a' && ch<='z'){
            ch=ch-32;
        }
        target.put(ch);
    }
    source.close();
    target.close();
    cout << "File copied successfully!";
    return 0;
}
