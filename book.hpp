#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class Book {
public:
    string title;
    string isbn;
    string author;
    string kindOfBook;
    double price;
    int quantity;

    // Constructor with correct syntax
    Book(string title, string isbn, string author, string kindOfBook, double price, int quantity) {
        this->title = title;
        this->isbn = isbn;
        this->author = author;
        this->kindOfBook = kindOfBook;
        this->price = price;
        this->quantity = quantity;
    }

    // Getters
    string gettitle() const { return title; }
    string getisbn() const { return isbn; }
    string getauthor() const { return author; }
    string getkindOfBook() const { return kindOfBook; }
    double getprice() const { return price; }
    int getquantity() const { return quantity; }

    // Setters (use this-> to refer to the member variable)
    void settitle(string title) { this->title = title; }
    void setisbn(string isbn) { this->isbn = isbn; }
    void setauthor(string author) { this->author = author; }
    void setkindOfBook(string kindOfBook) { this->kindOfBook = kindOfBook; }
    void setprice(double price) { this->price = price; }
    void setquantity(int quantity) { this->quantity = quantity; }

    // Save book data to file
    void save() {
        ofstream outfile("book.txt", ios::app);
        outfile << setw(10) << "TITLE" 
                << setw(10) << "ISBN" 
                << setw(10) << " AUTHOR "
                << setw(15) << "KIND OF BOOK " 
                << setw(10) << " PRICE " 
                << setw(12) << " QUANTITY " << endl;
        outfile << setw(10) << title 
                << setw(10) << isbn 
                << setw(10) << author 
                << setw(10) << kindOfBook 
                << setw(10) << price 
                << setw(10) << quantity << endl;
        outfile.close();
    }
};
