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
        cout << "Title: " << title << "\nAuthor: " << author 
             << "\nStatus: " << (isAvailable ? "Available" : "Checked Out") << endl;
    }

    void checkout() {
        if (isAvailable) {
            isAvailable = false;
            cout << "You successfully checked out \"" << title << "\"." << endl;
        } else {
            cout << "\"" << title << "\" is currently unavailable." << endl;
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "You returned \"" << title << "\"." << endl;
        } else {
            cout << "\"" << title << "\" was not checked out." << endl;
        }
    }
};

void printBookInfo(const LibraryBook& book) {
    cout << "\nBook Information" << endl;
    book.display();
}

int main() {
    LibraryBook myBook("To Kill a Mockingbird", "Harper Lee");

    printBookInfo(myBook);

    cout << endl;
    myBook.checkout();
    printBookInfo(myBook);

    cout << endl;
    myBook.returnBook();
    printBookInfo(myBook);

    return 0;
}
