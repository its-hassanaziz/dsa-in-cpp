#ifndef BOOK_H
#define BOOK_H

#include<string>
#include<fstream>
using namespace std;

class Book {
private:
	int bookId;
	string bookTitle;
	string authorName;
	double bookPrice;
	int bookQuantity;
public:
	Book() {
		setBookData(0, "", "", 0.0, 0);
	}

	Book(int id, string title, string author, double price, int quantity) {
		setBookData(id, title, author, price, quantity);
	}

	void setBookData(int id, string title, string author, double price, int quantity)
	{
		bookId = id;
		bookTitle = title;
		authorName = author;
		bookPrice = price;
		bookQuantity = quantity;
	}

	void setBookQuantity(int quantity)
	{
		bookQuantity = quantity;
	}
	int getBookId()   const {
		return bookId;
	}

	string getBookTitle()   const {
		return bookTitle;
	}

	string getAuthorName()   const {
		return authorName;
	}

	double getBookPrice()   const {
		return bookPrice;
	}

	int getBookQuantity()   const {
		return bookQuantity;
	}
};
#endif