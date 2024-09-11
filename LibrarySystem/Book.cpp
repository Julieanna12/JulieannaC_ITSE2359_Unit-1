#include "Book.h"
#include <iostream>
using namespace std;

//default constructor
Book::Book() : title(""), author(""), year(0), available(true) {}

//Parameterized constructor
Book::Book(std::string title, std::string author, int year, bool available)
    :title(title), author(author), yearPublished(year), available(available) {}

//Getter for the book title
string Book::getTitle() const {
    return title;
}

// Getter for the book author
string Book::getAuthor() cosnt {
    return author;
}

//Getter for the book publish year
int Book::getYearPublished() const {
    return yearPublished;
}

// Getter to check if the movie is available
bool Book::isAvailable() const{
    return available;
}

//Method to check book out (set available to false)
void Book::checkout() {
    if (available) {
        available = false;
    }
}

//Method to return the book (set available to true)
void Book::returnBook() {
    available = true;
}