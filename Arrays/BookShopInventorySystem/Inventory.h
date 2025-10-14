#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include"Book.h"
using namespace std;

class Inventory {
private:
	Book* bookList;
	static int booksCount;
public:
	Inventory() {
		booksCount = 0;
		loadInventoryData();
	}

	~Inventory() {
		delete[] bookList;
	}

	void loadInventoryData() {
		ifstream inventoryfile;
		inventoryfile.open("inventory.txt");

		int size = 0;
		int id, quantity;
		string title, author;
		double price;
		

		while (inventoryfile >> id) {
			inventoryfile >> title;
			inventoryfile >> author;
			inventoryfile >> price;
			inventoryfile >> quantity;
			size++;
		}
		booksCount = size;
		inventoryfile.close();

		bookList = new Book[size];

		ifstream inventoryFile;
		inventoryFile.open("inventory.txt");

		for (int i = 0; i < size; i++)
		{
			inventoryFile >> id;
			inventoryFile >> title;
			inventoryFile >> author;
			inventoryFile >> price;
			inventoryFile >> quantity;
			bookList[i].setBookData(id, title, author, price, quantity);
		}
		inventoryFile.close();
	}

	Book getBookList() const{
		return *bookList;
	}
	static int getBooksCount()  {
		return booksCount;
	}

	void addBook() {

		int quantity;
		string title, author;
		double price;

		cout << "\n<<===== Adding Book =====>>\n" << endl;
		cout << "Enter Book Name: ";
		cin >> title;
		cout << "Enter Author Name: ";
		cin >> author;
		cout << "Enter Book Price: ";
		cin >> price;
		cout << "Enter Book Quantity: ";
		cin >> quantity;

		Book* newBookList = new Book[booksCount + 1];

		for (int i = 0; i < booksCount; i++) {
			newBookList[i] = bookList[i];
		}

		newBookList[booksCount].setBookData(booksCount, title, author, price, quantity);

		delete[] bookList;
		bookList = newBookList;
		booksCount++;

		saveInventory();
		
		cout << "\n------ Book Added Succesfully ------\n" << endl;
	}

	void saveInventory()
	{
		ofstream inventoryFile;
		inventoryFile.open("inventory.txt");

		for (int i = 0; i < booksCount; i++) {
			inventoryFile << bookList[i].getBookId() << " \t\t"
				<< bookList[i].getBookTitle() << " \t\t"
				<< bookList[i].getAuthorName() << " \t\t"
				<< bookList[i].getBookPrice() << " \t\t"
				<< bookList[i].getBookQuantity() << endl;
		}
		inventoryFile.close();
	}
	void removeBook() {

		loadInventoryData();
		cout << "\n<<===== Removing Book =====>>\n" << endl;

		displayBooks();
		int id;
		cout << "Enter the ID of Book you want to remove: ";
		cin >> id;

		int indexToRemove = 0;
		for (int i = 0; i < booksCount; i++) {
			if (bookList[i].getBookId() == id) {
				indexToRemove = i;
				break;
			}
		}

		for (int i = indexToRemove; i < booksCount - 1; i++) {
			bookList[i] = bookList[i + 1];
		}

		booksCount--;
		saveInventory();
		cout << "\n------ Book Removed Succesfully ------\n" << endl;
	}

	void purchaseBook() {

		cout << "\n<<===== Performing Purchase Action =====>>\n" << endl;

		displayBooks();
		int id, quantity;
		cout << "Enter the ID of Book you want to purchase: ";
		cin >> id;
		cout << "Enter the Quantity of Books you want to purchase: ";
		cin >> quantity;

		if (id >= 0 && id <= booksCount) {
			bookList[id].setBookQuantity(bookList[id].getBookQuantity() - quantity);
			saveInventory();
			cout << "\n------ Book Purchased Succesfully ------\n" << endl;
		}
		else
			cout << "ERROR: Invalid Book Id" << endl;
	}

	void displayBooks() {
		cout << "\n<<================ Showing All Books ================>>\n" << endl;
		cout << left;
		cout << setw(5) << "ID" << setw(15) << "Title" << setw(15) << "Author"
			<< setw(10) << "Price" << setw(10) << "Quantity" << endl;

		for (int i = 0; i < booksCount; i++) {
			cout << setw(5) << bookList[i].getBookId()
				<< setw(15) << bookList[i].getBookTitle()
				<< setw(15) << bookList[i].getAuthorName()
				<< setw(10) << bookList[i].getBookPrice()
				<< setw(10) << bookList[i].getBookQuantity() << endl;
		}
	}

	void searchBookByID()
	{
		int id = 0;
		bool found = false;

		cout << "\n<<===== Searching by Book ID =====>>\n" << endl;
		cout << "Enter ID: ";
		cin >> id;

	
		for (int i = 0; i < booksCount; i++)
		{
			if(bookList[i].getBookId() == id)
			{
				found = true;

				cout << "Book Title: " << bookList[i].getBookTitle() << endl;
				cout << "Author Name: " << bookList[i].getAuthorName() << endl;
				cout << "Book Price: " << bookList[i].getBookPrice() << endl;
				cout << "Book Quantity: " << bookList[i].getBookQuantity() << endl;
			}
		}
		if (!found)
		{
			cout << "\n------ Book Not Found ------\n" << endl;
			return;
		}
		return;
	}

	void searchBookByKeyword() 
	{
		string key;
		bool found = false;

		cout << "\n<<===== Searching by Keyword =====>>\n" << endl;
		cout << "Enter Keyword: ";
		cin >> key;


		for (int i = 0; i < booksCount; i++)
		{
			if (bookList[i].getBookTitle() == key || bookList[i].getAuthorName() == key)
			{
				found = true;

				cout << "\nBook Title: " << bookList[i].getBookTitle() << endl;
				cout << "Author Name: " << bookList[i].getAuthorName() << endl;
				cout << "Book Price: " << bookList[i].getBookPrice() << endl;
				cout << "Book Quantity: " << bookList[i].getBookQuantity() << endl;
			}
		}
		if (!found)
		{
			cout << "\n------ Book Not Found ------\n" << endl;
			return;
		}
		return;
	}

};
#endif
