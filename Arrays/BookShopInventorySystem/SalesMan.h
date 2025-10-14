#ifndef SALESMAN_H
#define SALESMAN_H

#include<string>
#include<fstream>
#include"User.h"
#include"Inventory.h"
using namespace std;

class SalesMan : public User
{
private:
    string SalesManName;
public:
    SalesMan(string sMName, string name, string password) :User(name, password)
    {
        SalesManName = sMName;
    }
    bool loginCheck()
    {
        bool status = false;
        string name, password;

        ifstream salesManFile;
        salesManFile.open("salesManData.txt");

        if (!salesManFile) {
            cout << "Error: could not open salesManData.txt\n";
            return false;
        }



        while (salesManFile >> name) {
            salesManFile >> password;
            if (name == userName && password == userPassword) {
                status = true;
                return status;
            }
        }

        return status;
    }
    void showMenu()
    {
        int choice = 0;

        do {
            cout << "\n<<===== SalesMan Menu =====>>\n" << endl;
            cout << "1. Add Book\n";
            cout << "2. Remove Book\n";
            cout << "3. Search Book by ID\n";
            cout << "4. Search Book by Keyword\n";
            cout << "5. Purchase Book\n";
            cout << "6. View All Books\n";
            cout << "7. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

        } while (choice < 0 || choice > 7);

        Inventory inventory;

        switch (choice)
        {
        case 1:
            inventory.addBook();
            break;
        case 2:
            inventory.removeBook();
            break;
        case 3:
            inventory.searchBookByID();
            break;
        case 4:
            inventory.searchBookByKeyword();
            break;
        case 5:
            inventory.purchaseBook();
            break;
        case 6:
            inventory.displayBooks();
            break;
        case 7:
            cout << "\nLogging out...\n";
            return;
        default:
            cout << "Invalid choice. Try again.\n";

        }


    }

};
#endif