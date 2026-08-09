/*
Question 3:
Write a program with a class LibraryBook having private members title, author, and isAvailable.
Write const member functions getTitle(), getAuthor(), and display().
Write non-const functions checkOut() and returnBook().
Write a standalone function printBookInfo(const LibraryBook& book)
that prints book details using const reference.
*/

#include <iostream>
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
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Not Available") << endl;
    }

    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book is already checked out." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully." << endl;
    }
};

void printBookInfo(const LibraryBook& book) {
    cout << "Book Information:" << endl;
    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    book.display();
}

int main() {
    LibraryBook b1("OOP with C++", "E. Balagurusamy");

    printBookInfo(b1);

    cout << endl;
    b1.checkOut();
    b1.display();

    cout << endl;
    b1.returnBook();
    b1.display();

    return 0;
}