#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    bool isAvailable;

public:
    LibraryBook(string t, string a) {
        title = t;
        author = a;
        isAvailable = true;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    void display() const {
        cout << "Title : " << title << endl;
        cout << "Author: " << author << endl;

        if (isAvailable)
            cout << "Available\n";
        else
            cout << "Checked Out\n";
    }

    void checkout() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book Checked Out\n";
        }
        else {
            cout << "Already Issued\n";
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Book Returned\n";
    }
};

void printBookInfo(const LibraryBook& book) {
    book.display();
}

int main() {
    LibraryBook b1("C++ Programming", "Bjarne");

    printBookInfo(b1);

    b1.checkout();

    cout << "\nAfter Checkout:\n";
    b1.display();

    b1.returnBook();

    cout << "\nAfter Return:\n";
    b1.display();

    return 0;
}
