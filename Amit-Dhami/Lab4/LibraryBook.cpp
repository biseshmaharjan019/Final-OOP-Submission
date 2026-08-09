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
cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
void checkout() {
        isAvailable = false;
    }
void returnBook() {
        isAvailable = true;
    }
};
void printBookInfo(const LibraryBook& book) {
    book.display();
}
int main() {
    LibraryBook b1("C++ Programming", "Andha Einstein");
printBookInfo(b1);
b1.checkout();
    b1.display();
b1.returnBook();
    b1.display();

    return 0;
}
