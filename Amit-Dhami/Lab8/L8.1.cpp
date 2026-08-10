#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main()
{
    ifstream in("source.txt");
    ofstream out("destination.txt");

    if(!in || !out)
    {
        cout<<"File could not be opened."<<endl;
        return 0;
    }

    char ch;
    while(in.get(ch))
    {
        if(islower(ch))
            ch=toupper(ch);
        out.put(ch);
    }

    in.close();
    out.close();

    cout<<"File copied successfully with lowercase converted to uppercase."<<endl;

    return 0;
}
