// LibraryBook Class - Modified Author Name

#include <iostream>
#include <string>
#include <cstdlib>
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
        cout << "Status: " << (isAvailable ? "Available" : "Checked out") << endl;
    }

    void checkout() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book is already checked out." << endl;
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Book is already available." << endl;
        }
    }
};

void printBookInfo(const LibraryBook& book) {
    cout << "\nBook Information:" << endl;
    book.display();
    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
}

int main() {
    LibraryBook book("C++ Programming", "Scott Meyers");

    book.display();

    printBookInfo(book);

    book.checkout();
    book.display();

    book.returnBook();
    book.display();

    system("pause");
    return 0;
}
