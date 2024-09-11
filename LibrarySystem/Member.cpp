#include "Member.h"
#include <iostream>

using namespace std;


Member::Member() : name("") {}

Member::Member(string name) : name(name) {}

string Member::getName() const { return name; }

void Member::checkoutBook(Book& book) {
    if (book.isAvailable()) {
        book.checkout();
        CheckedoutBooks.push_back(book);
    }
}

void Member::returnBook(Book& book) {
    for (size_t i = 0; i < CheckedoutBooks.size(); i++) {
        if (CheckedoutBooks[i].getTitle() == book.getTitle()) {
            book.returnBook();
            CheckedoutBooks.erase(CheckedoutBooks.begin() + i);
            break;
        }
    }
}

void Member::displayCheckedoutBooks() const {
    cout << "Books checked out by " << name << ":\n";
    for (const auto& book : CheckedoutBooks) {
        cout << book.getTitle() << " (" << book.getYearPublished() << ")\n";
    }
}