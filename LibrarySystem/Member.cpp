#include "Member.h"
#include <iostream>

using namespace std;


Member::Member() : name("") {}

Member::Member(string name) : name(name) {}

string Member::getName() const { return name; }

void Member::checkoutBook(Book& book) {
    if (book.isAvailable()) {
        book.rent();
        checkedoutBooks.push_back(book);
    }
}

void Customer::returnBook(Book& book) {
    for (size_t i = 0; i < checkedoutBooks.size(); i++) {
        if (checkedoutBooks[i].getTitle() == book.getTitle()) {
            book.returnBook();
            checkedoutBooks.erase(checkedoutBooks.begin() + i);
            break;
        }
    }
}

void Customer::displayCheckedoutBooks() const {
    cout << "Books rented by " << name << ":\n";
    for (const auto& book : checkedoutBooks) {
        cout << book.getTitle() << " (" << book.getYear() << ")\n";
    }
}