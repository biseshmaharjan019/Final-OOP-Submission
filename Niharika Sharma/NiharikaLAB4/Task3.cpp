#include<iostream>
using namespace std;
class LibraryBook{
private:
	string title,author;
	bool isAvailable;
public:
	LibraryBook(string t,string a){
		title=t;
		author=a;
		isAvailable=true;
	}
	string getTitle() const {
		return title;
	}
	string getAuthor() const {
		return author;
	}
	void display() const {
		cout << "Title : " <<title <<endl;
		cout << "Author : " <<author <<endl;
		cout << "Available : " <<(isAvailable? "Yes":"No") <<endl;
	}
	void checkout(){
		if(isAvailable){
			isAvailable=false;
			cout << "Book Checked Out." <<endl;
		}
		else{
			cout << "Book Not Available!" <<endl;
		}
	}
	void returnBook(){
		isAvailable=true;
		cout << "Book Returned." <<endl;
	}
};
void printBookInfo(const LibraryBook &book){
	book.display();
}
int main()
{
	LibraryBook b("OOP","SP");
	printBookInfo(b);
	b.checkout();
	b.display();
	b.returnBook();
	b.display();
	return 0;
}
