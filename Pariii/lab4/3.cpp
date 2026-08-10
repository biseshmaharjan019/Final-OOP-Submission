#include <iostream>
using namespace std;

class LibraryBook
{
private:
    string t, a;
    bool av;

public:
    LibraryBook(string t1, string a1)
    {
        t = t1;
        a = a1;
        av = true;
    }

    string getTitle() const
    {
        return t;
    }

    string getAuthor() const
    {
        return a;
    }

    void display() const
    {
        cout << "Title: " << t << endl;
        cout << "Author: " << a << endl;
        cout << "Available: " << (av ? "Yes" : "No") << endl;
    }

    void checkout()
    {
        av = false;
    }

    void returnBook()
    {
        av = true;
    }
};

void printBookInfo(const LibraryBook &b)
{
    b.display();
}

int main()
{
    LibraryBook b("CPP", "Bjarne");

    b.display();

    b.checkout();
    b.display();

    b.returnBook();
    printBookInfo(b);

    return 0;
}