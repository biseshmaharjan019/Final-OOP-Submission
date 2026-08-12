/*
Library Management System
---------------------------------
Objectives:
1. To develop a computerized library records managing system.
2. To store and maintain details of books such as Book ID, Title,
   Author, and Availability.
3. To issue books and record their return.

Members:
1) Amit Dhami (HCE082 BF1004)
2) Bipesh Maharjan (009)
3) Saptal Bag Ghimire (018)
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>   // for atoi
#include <algorithm>

using namespace std;

// ---------------------------------------------------------
// Book class - stores details of a single book
// ---------------------------------------------------------
class Book {
public:
    int id;
    string title;
    string author;
    bool isAvailable; // true = available, false = issued
    string issuedTo;  // name of borrower (if issued)

    Book() : id(0), isAvailable(true) {}

    Book(int id, string title, string author)
        : id(id), title(title), author(author), isAvailable(true), issuedTo("") {}

    void display() const {
        cout << left;
        cout.width(6);  cout << id;
        cout.width(25); cout << title;
        cout.width(20); cout << author;
        cout.width(12); cout << (isAvailable ? "Available" : "Issued");
        if (!isAvailable) cout << "(To: " << issuedTo << ")";
        cout << endl;
    }
};

// ---------------------------------------------------------
// Library class - manages the collection of books
// ---------------------------------------------------------
class Library {
private:
    vector<Book> books;
    const string dataFile;

public:
    Library() : dataFile("library_data.txt") {
        loadFromFile();
    }

    ~Library() {
        saveToFile();
    }

    // ---------- Add a new book ----------
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        if (findBookIndex(id) != -1) {
            cout << "A book with this ID already exists!\n";
            return;
        }

        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    // ---------- Display all books ----------
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\nNo books in the library.\n";
            return;
        }
        cout << "\n" << left;
        cout.width(6);  cout << "ID";
        cout.width(25); cout << "Title";
        cout.width(20); cout << "Author";
        cout.width(12); cout << "Status";
        cout << endl;
        cout << string(70, '-') << endl;

        for (size_t i = 0; i < books.size(); i++) {
            books[i].display();
        }
    }

    // ---------- Search a book by ID or Title ----------
    void searchBook() const {
        if (books.empty()) {
            cout << "\nNo books in the library.\n";
            return;
        }

        int choice;
        cout << "\nSearch by:\n1. Book ID\n2. Title\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        bool found = false;
        if (choice == 1) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].id == id) {
                    books[i].display();
                    found = true;
                    break;
                }
            }
        } else if (choice == 2) {
            string title;
            cout << "Enter Title (or part of it): ";
            getline(cin, title);
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].title.find(title) != string::npos) {
                    books[i].display();
                    found = true;
                }
            }
        }

        if (!found) cout << "No matching book found.\n";
    }

    // ---------- Issue a book ----------
    void issueBook() {
        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;
        cin.ignore();

        int idx = findBookIndex(id);
        if (idx == -1) {
            cout << "Book not found.\n";
            return;
        }

        if (!books[idx].isAvailable) {
            cout << "Sorry, this book is already issued to "
                 << books[idx].issuedTo << ".\n";
            return;
        }

        string borrower;
        cout << "Enter borrower's name: ";
        getline(cin, borrower);

        books[idx].isAvailable = false;
        books[idx].issuedTo = borrower;
        cout << "Book \"" << books[idx].title << "\" issued to "
             << borrower << " successfully.\n";
    }

    // ---------- Return a book ----------
    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        int idx = findBookIndex(id);
        if (idx == -1) {
            cout << "Book not found.\n";
            return;
        }

        if (books[idx].isAvailable) {
            cout << "This book was not issued.\n";
            return;
        }

        cout << "Book \"" << books[idx].title << "\" returned by "
             << books[idx].issuedTo << ".\n";
        books[idx].isAvailable = true;
        books[idx].issuedTo = "";
    }

    // ---------- Delete a book record ----------
    void deleteBook() {
        int id;
        cout << "\nEnter Book ID to delete: ";
        cin >> id;

        int idx = findBookIndex(id);
        if (idx == -1) {
            cout << "Book not found.\n";
            return;
        }

        cout << "Deleted book: " << books[idx].title << "\n";
        books.erase(books.begin() + idx);
    }

    // ---------- File Handling ----------
    void saveToFile() const {
        ofstream out(dataFile.c_str());
        for (size_t i = 0; i < books.size(); i++) {
            out << books[i].id << "|" << books[i].title << "|" << books[i].author << "|"
                << books[i].isAvailable << "|" << books[i].issuedTo << "\n";
        }
        out.close();
    }

    void loadFromFile() {
        ifstream in(dataFile.c_str());
        if (!in) return;

        string line;
        while (getline(in, line)) {
            if (line.empty()) continue;
            vector<string> parts;
            size_t pos = 0, prev = 0;
            while ((pos = line.find('|', prev)) != string::npos) {
                parts.push_back(line.substr(prev, pos - prev));
                prev = pos + 1;
            }
            parts.push_back(line.substr(prev));

            if (parts.size() >= 5) {
                Book b;
                b.id = atoi(parts[0].c_str());
                b.title = parts[1];
                b.author = parts[2];
                b.isAvailable = (parts[3] == "1");
                b.issuedTo = parts[4];
                books.push_back(b);
            }
        }
        in.close();
    }

private:
    int findBookIndex(int id) const {
        for (size_t i = 0; i < books.size(); i++)
            if (books[i].id == id) return (int)i;
        return -1;
    }
};

// ---------------------------------------------------------
// Utility: clear invalid cin input
// ---------------------------------------------------------
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------------------------------------------------------
// Main menu
// ---------------------------------------------------------
int main() {
    Library library;
    int choice;

    cout << "=========================================\n";
    cout << " LIBRARY MANAGEMENT SYSTEM\n";
    cout << "=========================================\n";

    do {
        cout << "\n----------- MAIN MENU -----------\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Save & Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.displayAllBooks(); break;
            case 3: library.searchBook(); break;
            case 4: library.issueBook(); break;
            case 5: library.returnBook(); break;
            case 6: library.deleteBook(); break;
            case 7:
                library.saveToFile();
                cout << "Data saved. Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
