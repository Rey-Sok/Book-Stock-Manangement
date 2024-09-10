
#include <vector>
#include <sstream>
#include "book.hpp"
#include <fstream>
#include <iostream>

using namespace std;

// Function to load books from file
vector<Book> load_books() {
    vector<Book> book_data;
    ifstream book("book.txt");

    string line;
    while (getline(book, line)) {
        stringstream ss(line);
        string title, isbn, author, kindOfBook, price_str, quantity_str;
        double price;
        int quantity;

        if (getline(ss, title, ',') && getline(ss, isbn, ',') &&
            getline(ss, author, ',') && getline(ss, kindOfBook, ',') &&
            getline(ss, price_str, ',') && getline(ss, quantity_str, ',')) {

            price = stod(price_str); // Convert price to double
            quantity = stoi(quantity_str); // Convert quantity to int

            book_data.emplace_back(title, isbn, author, kindOfBook, price, quantity);
        }
    }
    book.close();
    return book_data;
}

// Function to stock in books
void stockIn() {
    vector<Book> books = load_books();  // Fixing the type to Book
        char ch;

    do {// Input new book data
        bool is_exist = false;
        string title, isbn, author, kindOfBook;
        double price;
        int quantity;
        cout << "=====| Creating new book | ======" << endl;
        cout << "Book title   : "; getline(cin >> ws, title);  // Use ws to clear whitespaces
        cout << "Book Isbn    : "; cin >> isbn;
        cin.ignore(); // Clear buffer before reading next input
        cout << "Book Author  : "; getline(cin, author);
        cout << "Kind Of Book : "; getline(cin, kindOfBook);
        cout << "Book Price   : "; cin >> price;
        cout << "Book Quantity: "; cin >> quantity;
        cout << "You created  ......" << endl;
        Book new_book(title, isbn, author, kindOfBook, price, quantity);
        books.push_back(new_book);
        cout << "Do you have any Book to add (Y/N) : " ;cin.ignore () ; cin >> ch;
    }while (ch != 'n' && ch != 'N');



    // Check if the book already exists, if so, update its quantity
    // for (auto& book : books) {
    //     if (book.isbn == new_book.isbn) {
    //         book.quantity += new_book.quantity;  // Update quantity if the book exists
    //         is_exist = true;
    //         break;
    //     }
    // }

    // If book doesn't exist, add it to the vector
    // if (!is_exist) {
    //     cout << "This function worked.";
    //     books.push_back(new_book);
    // }


    // Save updated book data back to file (truncate the file first)
    ofstream update_book("book.txt", ios::app);
    
    for (auto& book : books) {
        book.save();  // Save each book back to file
    }
    update_book.close();  // Close the file
}

void stockOut (){

}

void saleManagement (){

}

// Book Management System Menu (extend as needed)
void bookManagementSystem() {
    cout << "Welcome to Book Management System" << endl;
    cout << "1. Stock In" << endl;
    cout << "2. Stock Out" << endl;
    cout << "3. Sale Management" << endl;
}


