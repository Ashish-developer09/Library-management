#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Book {
public:
    string title;
    string author;
    int bookID;

    Book() {}

    Book(int id, string t, string a) : bookID(id), title(t), author(a) {}
};

class Library {
private:
    vector<Book> books;
    int nextID;

public:
    Library() : nextID(1) {}

    void addBook() {
        string title, author;
        cout << "Enter book title: ";
        cin.ignore(); // Ignore leftover newline character
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);

        Book newBook(nextID++, title, author);
        books.push_back(newBook);

        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }
        cout << "Books in Library:" << endl;
        for (const Book& b : books) {
            cout << "ID: " << b.bookID << ", Title: " << b.title << ", Author: " << b.author << endl;
        }
    }

    void searchBook() {
        int id;
        cout << "Enter book ID to search: ";
        cin >> id;

        for (const Book& b : books) {
            if (b.bookID == id) {
                cout << "Book found!" << endl;
                cout << "ID: " << b.bookID << ", Title: " << b.title << ", Author: " << b.author << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

void displayMenu() {
    cout << "\nLibrary Management System Menu" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Display Books" << endl;
    cout << "3. Search Book by ID" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
