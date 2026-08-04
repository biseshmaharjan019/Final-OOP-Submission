#include<iostream>
using namespace std;

class LibraryBook
{
private:
    string title,author;
    bool isAvailable;

public:
    LibraryBook(string t,string a,bool av=true)
    {
        title=t;
        author=a;
        isAvailable=av;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    void display() const
    {
        cout<<"Title : "<<title<<endl;
        cout<<"Author : "<<author<<endl;
        cout<<"Available : "<<isAvailable<<endl;
    }

    void checkout()
    {
        isAvailable=false;
    }

    void returnBook()
    {
        isAvailable=true;
    }
};

void printBookInfo(const LibraryBook &book)
{
    book.display();
}

int main()
{
    LibraryBook b("C++","Bjarne");

    printBookInfo(b);

    b.checkout();
    b.display();

    b.returnBook();
    b.display();

    return 0;
}